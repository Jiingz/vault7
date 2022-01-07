#include <Windows.h>
#include <core/tests/test_run.h>
#include <core/locator.h>
#include <core/libs/xor.h>
#include <string>
#include <core/sdk/controller.h>
using namespace core;

void core::TestRun::DrawMenu()
{

	ImGui::SetNextWindowSize({ 726.f,474.f });

	ImGui::Begin(xor ("DEBUG"));
	ImGui::SetCursorPos({ 422.f,64.f });
	ImGui::SetCursorPos({ 165.f,105.f });
	if (ImGui::Button(xor ("Test AIManager"), { 152.f,17.f }))
	{
		TestAIManager();
	}
	ImGui::SetCursorPos({ 164.f,66.f });
	if (ImGui::Button(xor ("Test Object"), { 152.f,19.f }))
	{
		RunObjectTest();
	}
	ImGui::SetCursorPos({ 30.f,30.f });


	ImGui::End();

}

void TestRun::RunObjectTest()
{
	core::Locator::GetGameComponents()->PrintChat(xor ("Running Object tests..."));

	if (!core::Locator::GetWorld()->GetPlayer())
	{
		core::Locator::GetGameComponents()->PrintChat(xor ("LocalPlayer invalid!"));
		return;
	}

	core::Locator::GetGameComponents()->PrintChat(xor ("Testing ManagerTemplates..."));


	for (auto unit : core::Locator::GetWorld()->GetAttackableUnits()) {}
	core::Locator::GetGameComponents()->PrintChat(xor ("AttackableUnits:Checked"));


	for (auto unit : core::Locator::GetWorld()->GetBuildings()) {}
	core::Locator::GetGameComponents()->PrintChat(xor ("Buildings:Checked"));

	for (auto unit : core::Locator::GetWorld()->GetHeroes()) {}
	core::Locator::GetGameComponents()->PrintChat(xor ("Heroes:Checked"));

	for (auto unit : core::Locator::GetWorld()->GetInhibitors()) {}
	core::Locator::GetGameComponents()->PrintChat(xor ("Inhibs:Checked"));

	for (auto unit : core::Locator::GetWorld()->GetMinions()) {}
	core::Locator::GetGameComponents()->PrintChat(xor ("Minions:Checked"));

	for (auto unit : core::Locator::GetWorld()->GetTurrets()) {}
	core::Locator::GetGameComponents()->PrintChat(xor ("Turrets:Checked"));

	for (auto unit : core::Locator::GetWorld()->GetShops()) {}
	core::Locator::GetGameComponents()->PrintChat(xor ("Shops:Checked"));


	core::Locator::GetGameComponents()->PrintChat(xor ("Testing Spell:"));

	core::Locator::GetGameComponents()->PrintChat(xor ("Level:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->spell_book->level).c_str());
	core::Locator::GetGameComponents()->PrintChat(xor ("CD max:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->spell_book->cooldown_max).c_str());
	core::Locator::GetGameComponents()->PrintChat(xor ("Mana requirement lvl 1:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->spell_book->spell_info->spell_data->mana_cost[0]).c_str());
	core::Locator::GetGameComponents()->PrintChat(xor ("Missile Name:"));
	core::Locator::GetGameComponents()->PrintChat(local_player->spell_book->spell_info->spell_data->missile_name);
	core::Locator::GetGameComponents()->PrintChat(xor ("Spell Name:"));
	core::Locator::GetGameComponents()->PrintChat(local_player->spell_book->spell_info->spell_data->spell_name);
	core::Locator::GetGameComponents()->PrintChat(xor ("SpellSLot Name:"));
	core::Locator::GetGameComponents()->PrintChat(local_player->spell_book->spell_info->spell_data->spell_slot_name);
	core::Locator::GetGameComponents()->PrintChat(xor ("Speed:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->spell_book->spell_info->spell_data->speed).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("---------------------------------------------------------"));
	for (size_t i = 0; i < 5; i++)
	{
		core::Locator::GetGameComponents()->PrintChat(xor (""));
	}

}

void TestRun::TestFunctions()
{


}

void core::TestRun::TestAIManager()
{
	core::Locator::GetGameComponents()->PrintChat(xor ("Moving:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->is_moving).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("Dash Speed:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->dash_speed).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("Is Dashing:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->is_dashing).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("is_dashing_raw:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->is_dashing_raw).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("Movespeed:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->moveSpeed).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("MavBegin:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->nav_begin.X).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("NavEnd:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->nav_end.X).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("Passed Waypoints Count:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->passed_waypoint_count).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("ServerPos:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->server_pos.X).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("Vector Velocity:"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->velocity.X).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("WayPoint"));
	core::Locator::GetGameComponents()->PrintChat(std::to_string(local_player->GetAIManager()->waypoint.X).c_str());

	core::Locator::GetGameComponents()->PrintChat(xor ("---------------------------------------------------------"));
	for (size_t i = 0; i <5; i++)
	{
		core::Locator::GetGameComponents()->PrintChat(xor (""));
	}
}
