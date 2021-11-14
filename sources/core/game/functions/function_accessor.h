#pragma once
#include <core/game/functions/function.h>
#include <core/game/game_objects/attackable_units/hero.h>
#include <attackable_units/AttackableUnit.h>

namespace game
{
	struct FunctionAccessor
	{
	private:
		typedef float(__cdecl* fnGetAttackDelay)(AttackableUnit* pObj);
		//	typedef bool(__cdecl* fnWorldToScreen)(Vector3* vecIn, Vector2* vecOut);
		typedef void(__thiscall* fnPrintChat)(DWORD chatInstance, const char* t_message, int t_color);
		typedef int(__thiscall* fnGetBaseDrawPos)(AttackableUnit* object, Vector3* position);
		typedef float(__cdecl* fnGetAttackCastDelay)(AttackableUnit* pObj);
		typedef void** (__thiscall* fnGetBasicAttack)(AttackableUnit* obj, unsigned int slot); //SpellData**

	public:
		FunctionAccessor();

		Function<float, fnGetAttackDelay, AttackableUnit*> GetAttackDelay;
	};
}