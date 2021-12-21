#include <Windows.h>
#include "player.h"
#include <core/game/Offsets.h>
#include <core/locator.h>

using namespace game;

bool Player::Attack(AttackableUnit* unit) const
{
	const DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)((DWORD)GetModuleHandle(NULL) + Offsets::GameClient::HudInstance) + 0x24);

	Vector2 screen_pos_{ 0,0 };
	if (!core::Locator::GetFunctionAccessor()->WorldToScreen(&unit->position.value, &screen_pos_))
		return false;

	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 1, true, screen_pos_.X, screen_pos_.Y, 1, 1, 1);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 1, true, screen_pos_.X, screen_pos_.Y, 1, 1, 1);

	return true;
}

bool Player::Move(Vector3 pos) const
{
	const DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)((DWORD)GetModuleHandle(NULL) + Offsets::GameClient::HudInstance) + 0x24);

	Vector2 screen_pos_{ 0,0 };
	if (!core::Locator::GetFunctionAccessor()->WorldToScreen(&pos, &screen_pos_))
		return false;
	 
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, screen_pos_.X, screen_pos_.Y, 0, 1, 1);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, screen_pos_.X, screen_pos_.Y, 0, 1, 1);

	return true;
}