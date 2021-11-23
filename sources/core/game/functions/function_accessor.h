#pragma once
#include <core/game/functions/function.h>
#include <core/geometry/vector.h>

namespace game
{
	struct FunctionAccessor
	{
	public:
		// int thisptr, int State, int IsAttack, int isAttackCommand, int screen_x, int screen_y, char unknown1, char unknown2, char unknown3
		Function<CallingConvention::Thiscall, int, Offsets::IssueClick, int, int, int, int, int, int, char, char, char> IssueOrder;

		// int HudSpellLogic, int Slot, int always4, int State
		Function<CallingConvention::Thiscall, int, Offsets::IssueSpell, int, int, int, int> CastSpell;

		Function<CallingConvention::Cdecl, bool, Offsets::WorldToScreen, Vector3*, Vector2*> WorldToScreen;
		Function<CallingConvention::Thiscall, void, Offsets::PrintChat, DWORD, const char*, int> PrintChat;
		Function<CallingConvention::Thiscall, int, Offsets::BaseDrawPosition, AttackableUnit*, Vector3*> GetBaseDrawPos;
		Function<CallingConvention::Cdecl, float, Offsets::GetAttackDelay, AttackableUnit*> GetAttackDelay;
		Function<CallingConvention::Cdecl, float, Offsets::GetAttackCastDelay, AttackableUnit*> GetAttackCastDelay;
		Function <CallingConvention::Thiscall, void**, Offsets::GetBasicAttack, AttackableUnit*, unsigned int> GetbaseAttack; // void** = SpellData**
	};
}