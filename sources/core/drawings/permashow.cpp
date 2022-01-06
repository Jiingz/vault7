#include <Windows.h>
#include <core/drawings/permashow.h>
#include <core/features/orbwalker.h>
#include <core/features/feature_controller.h>
#include <core/libs/xor.h>
#pragma warning(disable : 4996) //disable unsafe warning for sprintf
using namespace drawings;

bool PermaShow::permashow_active_ = true;

void PermaShow::DrawPermaShow()
{
	if (!permashow_active_)
		return;

	ImGui::SetNextWindowSize({ 231.f,109.f });

	ImGui::Begin(xor ("Permashow"), &permashow_active_, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::SetCursorPos({ 7.f,28.f });
	ImGui::PushItemWidth(119.000000);
	ImGui::Text(GetOrbwalkerMode());
	ImGui::PopItemWidth();
	ImGui::SetCursorPos({ 7.f,52.f });
	ImGui::PushItemWidth(119.000000);
	ImGui::Text(xor ("Utilities: Active"));
	ImGui::PopItemWidth();


	ImGui::End();
}

const char* drawings::PermaShow::GetOrbwalkerMode()
{
	if (feature::FeatureController::GetOrbwalker()->GetOrbwalkerState() == feature::Orbwalker::orbwalker_state::attacking
		|| feature::FeatureController::GetOrbwalker()->GetOrbwalkerState() == feature::Orbwalker::orbwalker_state::moving)
		return "Orbwalker: Active";
	else return "Orbwalker: Inactive";
}
