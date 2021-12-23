#pragma once
#include <wtypes.h>
#include <memory>
#include <core/drawings/geometry/vector.h>

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