#pragma once
#include <wtypes.h>
#include <memory>
#include <core/drawings/geometry/vector.h>
#include <core/game/game_objects/game_object.h>

namespace game
{
	class GameComponent
	{
	public:
		GameComponent();

		Vector3 GetMouseWorldPos();
		void PrintChat(const char* message);

	private:
		DWORD* chat_instance_;
		DWORD hud_instance_;
	};
}