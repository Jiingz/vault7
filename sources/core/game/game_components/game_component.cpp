#include <core/game/game_components/game_component.h>
#include <core/memory/accessor.h>
#include <core/game/Offsets.h>

using namespace game;

GameComponent::GameComponent()
{
	this->hud_instance_ = (DWORD)GetModuleHandleA(NULL) + Offsets::HudInstance; //HudInstance isn't a pointer, but is being used to access pointers!
	this->chat_instance_ = memory::Accessor::AccessModuleAddress<DWORD*, Offsets::ChatInstance>();
}

DWORD GameComponent::GetHudInstance()
{
	return this->hud_instance_;
}

DWORD* game::GameComponent::GetChatInstance()
{
	return this->chat_instance_;
}

Vector3 GameComponent::GetMouseWorldPos()
{
	auto aux1 = *reinterpret_cast<DWORD*>(this->hud_instance_);
	aux1 += 0x14;
	auto aux2 = *reinterpret_cast<DWORD*>(aux1);
	aux2 += 0x1C;

	return *reinterpret_cast<Vector3*>(aux2);
}
