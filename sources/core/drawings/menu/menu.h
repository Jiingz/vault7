#pragma once
#include <core/libs/ImGui/imgui.h>
#include <core/libs/xor.h>
#include <core/features/feature_controller.h>
#include <Windows.h>
#include <core/drawings/permashow.h>

namespace mainMenu
{

	static void CustomColor() {
		auto* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(0.30f, 0.52f, 0.48f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.09f, 0.09f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.08f, 0.13f, 0.13f, 1.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.56f, 0.47f, 0.22f, 1.00f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.09f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.15f, 0.34f, 0.34f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.15f, 0.34f, 0.34f, 0.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.11f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.11f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.09f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.37f, 0.35f, 0.23f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.31f, 0.52f, 0.48f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.31f, 0.52f, 0.48f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.08f, 0.13f, 0.13f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.10f, 0.20f, 0.19f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.35f, 0.58f, 0.86f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
		colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.41f, 0.68f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
		colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
		colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
		colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	}



	static void CustomStyle() {
		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowPadding = ImVec2(5, 5);
		style.FramePadding = ImVec2(8, 4);
		style.CellPadding = ImVec2(4, 3);
		style.ItemSpacing = ImVec2(8, 4);
		style.ItemInnerSpacing = ImVec2(4, 4);
		style.TouchExtraPadding = ImVec2(0, 0);
		style.IndentSpacing = 14;
		style.ScrollbarSize = 1;
		style.GrabMinSize = 10;
		style.WindowBorderSize = 1;
		style.ChildBorderSize = 1;
		style.PopupBorderSize = 1;
		style.FrameBorderSize = 0;
		style.TabBorderSize = 0;
		style.WindowRounding = 0;//7;
		style.ChildRounding = 0;
		style.FrameRounding = 5;
		style.PopupRounding = 0;
		style.ScrollbarRounding = 0;
		style.GrabRounding = 5;
		style.LogSliderDeadzone = 3;
		style.TabRounding = 4;
		style.WindowTitleAlign = ImVec2(0.5f, 0.9f);
		style.WindowMenuButtonPosition = 0;
		style.ColorButtonPosition = 1;
		style.ButtonTextAlign = ImVec2(0, 0);
		style.SelectableTextAlign = ImVec2(0, 0);
		style.DisplaySafeAreaPadding = ImVec2(3, 3);
	}


	namespace settings
	{
		static	bool open;
	}

	enum active_menu
	{
		coreMenu,
		orbwalker,
		champion,
		name_changer
	};


	static active_menu active_menu_ = active_menu::orbwalker;

	static void DrawMenu()
	{
		ImGui::SetNextWindowSize({ 726.f,474.f });

		ImGui::Begin("Vault7", &settings::open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
		CustomStyle();
		CustomColor();
		ImGui::SetCursorPos({ -27.f,11.f });

		ImGui::BeginChild("child0", { 152.f,470.f }, true);

		ImGui::SetCursorPos({ 29.f,26.f });
		if (ImGui::Button("CORE", { 152.f,19.f }))
		{
			active_menu_ = active_menu::coreMenu;
		}
		ImGui::SetCursorPos({ 29.f,76.f });
		if (ImGui::Button("ORBWALKER", { 152.f,19.f }))
		{
			active_menu_ = active_menu::orbwalker;
		}
		ImGui::SetCursorPos({ 25.f,126.f });
		if (ImGui::Button("CHAMPION", { 152.f,19.f }))
		{

		}
		ImGui::SetCursorPos({ 29.f,179.f });
		if (ImGui::Button("NAME CHANGER", { 152.f,19.f }))
		{

		}
		bool the_bool;
		ImGui::EndChild();

		switch (active_menu_)
		{
		case active_menu::orbwalker:
			feature::FeatureController::GetOrbwalker()->DrawMenu();
		}

		ImGui::End();


		permashow::DrawPermaShow();


	}

}

