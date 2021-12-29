#include <core/game/game_components/game_component.h>
#include <core/memory/accessor.h>
#include <core/game/Offsets.h>
#include <core/locator.h>

using namespace game;

GameComponent::GameComponent()
{
	this->hud_instance_ = DEFINE_RVA(Offsets::HudInstance); //HudInstance isn't a pointer, but is being used to access pointers!
	this->chat_instance_ = memory::Accessor::AccessModuleAddress<DWORD*, Offsets::ChatInstance>();
}

Vector3 GameComponent::GetMouseWorldPos()
{
	DWORD MousePtr = DEFINE_RVA(Offsets::GameClient::HudInstance);
	auto aux1 = *(DWORD*)MousePtr;
	aux1 += 0x14;
	auto aux2 = *(DWORD*)aux1;
	aux2 += 0x1C;

	Vector3 temp;

	temp.X = *(float*)(aux2 + 0x0);
	temp.Y = *(float*)(aux2 + 0x4);
	temp.Z = *(float*)(aux2 + 0x8);

	return temp;
}

void game::GameComponent::PrintChat(const char* message)
{
	core::Locator::GetFunctionAccessor()->PrintChat(*this->chat_instance_, message, 0xFFFFFF);
}
