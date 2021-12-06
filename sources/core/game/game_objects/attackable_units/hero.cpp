#include <Windows.h>

#include <attackable_units/hero.h>
#include <core/memory/accessor.h>
#include <core/game/Offsets.h>
#include <core/locator.h>

void Hero::IssueOrder(AttackableUnit* target)
{
	const DWORD hud_input_logic_ = *memory::Accessor::AccessModuleAddress<DWORD*, Offsets::HudInstance>(0x24);

	Vector2 screen_pos_;
	core::Locator::GetFunctionAccessor()->WorldToScreen(&this->position.value, &screen_pos_);

	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 1, true, screen_pos_.X, screen_pos_.Y, 1, 1, 1);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 1, true, screen_pos_.X, screen_pos_.Y, 1, 1, 1);
}

void Hero::IssueOrder(Vector3* move_pos)
{
	const DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)((DWORD)GetModuleHandle(NULL) + Offsets::HudInstance) + 0x24);

	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, 0, 0, 0, 1, 1);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, 0, 0, 0, 1, 1);
}
