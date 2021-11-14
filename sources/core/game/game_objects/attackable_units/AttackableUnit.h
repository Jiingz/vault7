#pragma once
#include <core/game/game_objects/game_object.h>
namespace game::gameObjects
{
	class AttackableUnit : public game::gameObjects::GameObject
	{
	public:
		float GetAttackDelay();
	};
}