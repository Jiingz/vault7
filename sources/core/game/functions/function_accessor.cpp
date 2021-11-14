#include <Windows.h>
#include <core/game/functions/function_accessor.h>

using namespace game;

FunctionAccessor::FunctionAccessor()
{
	this->GetAttackDelay = Function<float, fnGetAttackDelay, AttackableUnit*>(0x2848F0);
}