#include <loader/views/app_view.h>
#include <loader/app/module_loader.h>
#include <loader/app/locator.h>

#include <wrl/client.h>

#include <IconsMaterialDesign.h>
#include <imgui.h>

#include <filesystem>
#include <iostream>


using namespace Microsoft::WRL;
using namespace loader::views;
using namespace loader;


AppView::AppView()
    : modules_loaded_(false)
{
}

void AppView::Initialize()
{
    modules_ = Locator::GetModules();

    auto font_resources = Locator::GetFonts();

    md_main_font_ = &font_resources->Get(TEXT("md-main-font"));
    md_material_font_ = &font_resources->Get(TEXT("md-material-font"));
    lg_material_font_ = &font_resources->Get(TEXT("lg-material-font"));
}


void AppView::Render()
{
    {
        ImGui::BeginChild("ModuleWindow", ImVec2(390.0f, 500.0f), true, ImGuiWindowFlags_AlwaysAutoResize);

        if (ImGui::Button("Load Modules", ImVec2(150.0f, 0.0f)))
        {
            this->LoadModules();
        }

        for (auto it = modules_->Begin(); it != modules_->End();)
        {
            if (!this->RenderModule(it))
            {
                ++it;
            }
        }

        ImGui::EndChild();
    }

    ImGui::SameLine(0.0f, 5.0f);

    {
        ImGui::BeginChild("InformationWindow", ImVec2(390.0f, 500.0f), true, ImGuiWindowFlags_AlwaysAutoResize);

        ImGui::EndChild();
    }

    const ImVec2 region = ImGui::GetContentRegionMax();
    ImGui::SetCursorPosY(region.y - 50.0f);

    if (ImGui::Button("Inject", ImVec2(-1.0f, 35.0f)))
    {
    }
}


bool AppView::RenderModule(ResourceHolder<sdk::ModuleBase>::Iterator it)
{
    static bool enabled = true;
    bool removed = false;

    const auto module_filename = it->first;
    const auto info = it->second->GetModuleInfo();

    std::string child_name;
    child_name.resize(module_filename.size());

    WideCharToMultiByte(CP_ACP, 0, module_filename.c_str(), module_filename.size(), &child_name[0], module_filename.size(), nullptr, nullptr);

    ImGui::BeginChild(child_name.c_str(), ImVec2(-1.0f, 100.0f), true);

    ImGui::PushFont(lg_material_font_);
    ImGui::Text(ICON_MD_EXTENSION);
    ImGui::PopFont();

    ImGui::SameLine();

    ImGui::SetCursorPosY(ImGui::GetFont()->FontSize);
    ImGui::Text((info.name + " by " + info.author + " - " + info.version).c_str());

    // ImGui::SameLine(ImGui::GetContentRegionMax().x - 18.0f);
    // ImGui::Checkbox("", &enabled);

    ImGui::PushFont(md_material_font_);
    ImGui::Text(ICON_MD_INFO);
    ImGui::PopFont();

    ImGui::SameLine(0.0f, 2.0f);

    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2.0f);
    ImGui::TextDisabled("Champions");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();

        ImGui::Text("Ezreal");

        ImGui::EndTooltip();
    }

    // Footer
    const ImVec2 max_region = ImGui::GetContentRegionMax();
    ImGui::SetCursorPosY(max_region.y - 20.0f);

    std::string enable_disable_text = enabled ? "Disable" : "Enable";

    if (enabled)
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(220.0f / 255.0f, 53.0f / 255.0f, 69.0f / 255.0f, 1.0f));
    else
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(40.0f / 255.0f, 167.0f / 255.0f, 69.0f / 255.0f, 1.0f));

    if (ImGui::Button(enable_disable_text.c_str()))
    {
        enabled = !enabled;
    }

    ImGui::PopStyleColor();

    ImGui::SameLine();

    if (ImGui::Button("Remove"))
    {
        this->RemoveModule(it++);
        removed = true;
    }

    ImGui::EndChild();
    return removed;
}


void AppView::RemoveModule(ResourceHolder<sdk::ModuleBase>::Iterator it)
{
    const auto module_filename = it->first;

    WCHAR current_dir[MAX_PATH];
    GetModuleFileName(nullptr, current_dir, MAX_PATH);

    std::filesystem::path file_to_remove =
        std::filesystem::path(current_dir).parent_path() /
        TEXT("modules") /
        std::filesystem::path(module_filename).filename();

    if (DeleteFile(file_to_remove.wstring().c_str()))
    {
        modules_->Remove(it);
    }
}


void AppView::LoadModules()
{
    ComPtr<IFileOpenDialog> dialog;
    
    if (SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_ALL, IID_IFileOpenDialog, &dialog)))
    {
        COMDLG_FILTERSPEC filter_specs[] =
        {
            { TEXT("Vault7 Modules"), TEXT("*.dll") }
        };

        dialog->SetFileTypes(ARRAYSIZE(filter_specs), filter_specs);
        dialog->SetOptions(FOS_ALLOWMULTISELECT);

        HRESULT result = dialog->Show(nullptr);

        if (SUCCEEDED(result))
        {
            ComPtr<IShellItemArray> items_array;
            result = dialog->GetResults(&items_array);

            if (SUCCEEDED(result))
            {
                ComPtr<IEnumShellItems> enumerator;
                items_array->EnumItems(&enumerator);

                ULONG fetched = 0;

                // Get current folder to build the path to the modules folder. If it does not exists create it.
                WCHAR current_dir[MAX_PATH];
                GetModuleFileName(nullptr, current_dir, MAX_PATH);

                std::filesystem::path modules_dir = std::filesystem::path(current_dir).parent_path() / std::filesystem::path("modules");
                CreateDirectory(modules_dir.c_str(), nullptr);

                do
                {
                    // Iterate over each selected module dll and copy it to the modules folder.
                    ComPtr<IShellItem> item;
                    if (SUCCEEDED(enumerator->Next(1, &item, &fetched)) && fetched != 0)
                    {
                        PWSTR module_display_name = nullptr;
                        result = item->GetDisplayName(SIGDN_FILESYSPATH, &module_display_name);

                        std::filesystem::path path = module_display_name;

                        auto module = ModuleLoader().LoadModule(path.wstring());
                        
                        if (!module)
                        {
                            continue;
                        }

                        modules_->Store(module_display_name, std::move(module));

                        CopyFile(path.wstring().c_str(), (modules_dir / path.filename()).wstring().c_str(), FALSE);

                        if (SUCCEEDED(result))
                        {
                            CoTaskMemFree(module_display_name);
                        }
                    }

                } while (fetched != 0);
            }
        }
    }
}

