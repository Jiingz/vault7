#include <Windows.h>
#include "player.h"
#include <core/game/Offsets.h>
#include <core/locator.h>

using namespace game;

bool Player::Attack(AttackableUnit* unit) const
{
	DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)DEFINE_RVA(Offsets::HudInstance) + 0x24);

	Vector3 unit_position_ = unit->position;
	Vector2 screen_pos_;
	if (!core::Locator::GetFunctionAccessor()->WorldToScreen(&unit_position_, &screen_pos_))
		return false;


	core::Locator::GetGameComponents()->PrintChat(std::to_string(screen_pos_.X).c_str());
	core::Locator::GetGameComponents()->PrintChat(std::to_string(screen_pos_.Y).c_str());
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, screen_pos_.X, screen_pos_.Y, 1);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, screen_pos_.X, screen_pos_.Y, 1);

	return true;
}

bool Player::Move(Vector3 pos) const
{
	DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)DEFINE_RVA(Offsets::GameClient::HudInstance) + 0x24);

	Vector2 screen_pos_;
	if (!core::Locator::GetFunctionAccessor()->WorldToScreen(&pos, &screen_pos_))
		return false;

	POINT mouse;
	GetCursorPos(&mouse);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, mouse.x, mouse.y, 0);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, mouse.x, mouse.y, 0);

	return true;
}