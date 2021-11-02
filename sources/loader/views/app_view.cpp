#include <loader/views/app_view.h>
#include <loader/app/module_loader.h>

#include <wrl/client.h>

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


void AppView::Render()
{
    {
        ImGui::BeginChild("Left", ImVec2(390.0f, 500.0f), true, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Text("Something");
        ImGui::EndChild();
    }

    ImGui::SameLine(0.0f, 5.0f);

    {
        ImGui::BeginChild("Right", ImVec2(390.0f, 500.0f), true, ImGuiWindowFlags_AlwaysAutoResize);

        ImGui::Text("Something");
        ImGui::EndChild();
    }

    const ImVec2 region = ImGui::GetContentRegionMax();
    ImGui::SetCursorPosY(region.y - 50.0f);

    if (ImGui::Button("Inject", ImVec2(-1.0f, 35.0f)))
    {
    }

    /*
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Modules"))
        {
            if (ImGui::MenuItem("Load"))
            {
                this->LoadModules();

                // Set the flag that we loaded new modules.
                modules_loaded_ = !loaded_module_information_.empty();
            }

            if (ImGui::MenuItem("Remove all")) { }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    // Open popup window to select modules.
    if (modules_loaded_)
    {
        ImGui::OpenPopup("ModuleSelectionPopup");
        modules_loaded_ = false;
    }

    // Module selection popup
    if (ImGui::BeginPopupModal("ModuleSelectionPopup", 0, ImGuiWindowFlags_AlwaysAutoResize))
    {
        for (const auto& info : loaded_module_information_)
        {
            ImGui::Text(info.name.c_str());
        }

        if (ImGui::Button("Close"))
        {
            loaded_module_information_.clear();
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
    */
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
                GetCurrentDirectory(MAX_PATH, current_dir);

                std::filesystem::path target_dir = current_dir / std::filesystem::path("modules");
                CreateDirectory(target_dir.c_str(), nullptr);

                do
                {
                    // Iterate over each selected module dll and copy it to the modules folder.
                    ComPtr<IShellItem> item;
                    if (SUCCEEDED(enumerator->Next(1, &item, &fetched)) && fetched != 0)
                    {
                        PWSTR module_display_name = nullptr;
                        result = item->GetDisplayName(SIGDN_FILESYSPATH, &module_display_name);

                        WCHAR m[] = TEXT("modules");

                        std::filesystem::path path = module_display_name;

                        auto module = ModuleLoader().LoadModule(path.wstring());
                        
                        if (!module)
                        {
                            continue;
                        }

                        loaded_module_information_.push_back(module->GetExportInfo());

                        // std::filesystem::path target_file = target_dir / path.filename();
                        // 
                        // CopyFile(path.c_str(), target_file.c_str(), FALSE);

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

