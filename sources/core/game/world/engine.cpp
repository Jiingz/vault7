#include <core/game/world/engine.h>
#include <core/memory/accessor.h>
#include <core/game/Offsets.h>
using namespace game;

Engine::Engine()
{
	this->chat_instance_ = memory::Accessor::AccessModuleAddress<DWORD*,Offsets::ChatInstance>();
}