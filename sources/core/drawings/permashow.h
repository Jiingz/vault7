/* GENERATED WITH IMGUI BUILDER :) HAS 2 Objs & 1 forms */

#include <core/libs/ImGui/imgui.h>
namespace permashow
{
	namespace settings
	{
		static bool active;
	}

	static void DrawPermaShow()
	{
		ImGui::SetNextWindowSize({ 231.f,109.f });

		ImGui::Begin("Permashow", &settings::active, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

		ImGui::SetCursorPos({ 7.f,28.f });
		ImGui::PushItemWidth(119.000000);
		ImGui::Text("Orbwalker: Active");
		ImGui::PopItemWidth();
		ImGui::SetCursorPos({ 7.f,52.f });
		ImGui::PushItemWidth(119.000000);
		ImGui::Text("Utilities: Active");
		ImGui::PopItemWidth();


		ImGui::End();
	}



}