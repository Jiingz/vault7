#include <Windows.h>
#include "player.h"
#include <core/game/Offsets.h>
#include <core/locator.h>

using namespace game;
static bool decryption = false;
bool Player::Attack(AttackableUnit* unit) const
{
	DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)DEFINE_RVA(Offsets::HudInstance) + 0x24);

	Vector3 unit_position_ = unit->position;
	Vector2 screen_pos_;
	if (!core::Locator::GetWorld()->WorldToScreen(&unit_position_, &screen_pos_))
		return false;

	if (!decryption)
	{
		//do this once, else W2S Fails.
		std::string x = std::to_string(screen_pos_.X);
		std::string y = std::to_string(screen_pos_.Y);
		decryption = true;
	}


	//this is commented out, because it started crashing randomly. I love this game :)))
	/*core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, screen_pos_.X, screen_pos_.Y, 1);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, screen_pos_.X, screen_pos_.Y, 1);*/
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, screen_pos_.X, screen_pos_.Y, 1);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, screen_pos_.X, screen_pos_.Y, 1);

	return true;
}

bool Player::Move(Vector3 pos) const
{
	DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)DEFINE_RVA(Offsets::GameClient::HudInstance) + 0x24);


	POINT mouse;
	GetCursorPos(&mouse);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, mouse.x, mouse.y, 0);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, mouse.x, mouse.y, 0);

	return true;
}