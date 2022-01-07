#include <Windows.h>
#include <core/sdk/controller.h>
#include <core/locator.h>

using namespace sdk;

int Controller::Attack(AttackableUnit* target)
{
	Vector2 w2s;

	if (!core::Locator::GetFunctionAccessor()->WorldToScreen(&target->position, &w2s))
		return -1;

	DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)DEFINE_RVA(Offsets::HudInstance) + 0x24);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, w2s.X, w2s.Y, 0);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, w2s.X, w2s.Y, 0);
}

int Controller::Move(Vector3* pos)
{
	Vector2 w2s;

	if (!core::Locator::GetFunctionAccessor()->WorldToScreen(pos, &w2s))
		return -1;

	DWORD hud_input_logic_ = *(DWORD*)(*(DWORD*)DEFINE_RVA(Offsets::HudInstance) + 0x24);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 0, 0, true, w2s.X, w2s.Y, 0);
	core::Locator::GetFunctionAccessor()->NewIssueOrder(hud_input_logic_, 1, 0, true, w2s.X, w2s.Y, 0);
}