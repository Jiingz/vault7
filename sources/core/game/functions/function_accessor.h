#pragma once
#include <core/game/functions/function.h>
#include <core/drawings/geometry/vector.h>
#include <core/game/Offsets.h>
#include <core/game/game_objects/attackable_units/AttackableUnit.h>
namespace game
{
	struct FunctionAccessor
	{
	public:
		// int hudInputLogic, int State, int IsAttack, int isAttackCommand, int screen_x, int screen_y, char unknown3
		Function<CallingConvention::Thiscall, int, Offsets::NewIssueOrder, DWORD, int, int, int, int, int, char> NewIssueOrder;

		// int HudSpellLogic, int Slot, int always4, int State
		Function<CallingConvention::Thiscall, int, Offsets::NewCastSpell, int, int, int, int> NewCastSpell;

		// not working for some reason ???
		Function<CallingConvention::Cdecl, bool, Offsets::WorldToScreen, Vector3*, Vector2*> WorldToScreen;

		// chatInstance | message | color
		Function<CallingConvention::Thiscall, void, Offsets::PrintChat, DWORD, const char*, int> PrintChat;
		Function<CallingConvention::Thiscall, int, Offsets::BaseDrawPosition, AttackableUnit*, Vector3*> GetBaseDrawPos;
		Function<CallingConvention::Cdecl, float, Offsets::GetAttackDelay, AttackableUnit*> GetAttackDelay;
		Function<CallingConvention::Cdecl, float, Offsets::GetAttackCastDelay, AttackableUnit*> GetAttackCastDelay;
		Function <CallingConvention::Thiscall, void**, Offsets::GetBasicAttack, AttackableUnit*, unsigned int> GetbaseAttack; // void** = SpellData**
	};
}