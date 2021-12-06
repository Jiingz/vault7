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
		DWORD GetHudInstance();
		DWORD* GetChatInstance();

		Vector3 GetMouseWorldPos();

	private:
		DWORD* chat_instance_;
		DWORD hud_instance_;
	};
}