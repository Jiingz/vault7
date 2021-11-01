#include <loader/views/app_view.h>

#include <wrl/client.h>

#include <imgui.h>

#include <filesystem>
#include <iostream>
#include <vector>


using namespace Microsoft::WRL;
using namespace loader::views;


void AppView::Render()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Modules"))
        {
            if (ImGui::MenuItem("Load")) this->LoadModules();
            if (ImGui::MenuItem("Remove all")) { }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
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
                        std::filesystem::path target_file = target_dir / path.filename();

                        std::wcout << TEXT("copying ") << path.c_str() << target_file.c_str() << "\n";

                        CopyFile(path.c_str(), target_file.c_str(), FALSE);

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

