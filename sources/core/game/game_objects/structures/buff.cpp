#include <Windows.h>
#include <core/game/game_objects/structures/buff.h>
#include <core/game/Offsets.h>

using namespace game;

BYTE Buff::GetType()const noexcept
{
	return *(BYTE*)(this + Offsets::BuffManager::type);
}

bool Buff::IsAlive()const
{
	float time = *reinterpret_cast<float*>((DWORD)GetModuleHandle(NULL) + Offsets::GameTime);
	return GetStartTime() < time && time < GetEndTime();
}

bool Buff::IsValid()const
{
	if (this == nullptr || (DWORD)this <= 0x1000)
		return false;
	return strcmp(GetName(), "nullptr") && GetCountAlt() > 0;
}

float Buff::GetStartTime()const noexcept
{
	return *(float*)(this + Offsets::BuffManager::start_time);
}

float Buff::GetEndTime()const noexcept
{
	return *(float*)(this + Offsets::BuffManager::end_time);
}

DWORD Buff::GetCountAlt()const noexcept
{
	return (*(DWORD*)(this + Offsets::BuffManager::count_alt_one) - *(DWORD*)(this + Offsets::BuffManager::count_alt_two)) >> 3;
}

const char* Buff::GetName()const
{
	DWORD aux = *(DWORD*)(this + Offsets::BuffManager::name);
	if (aux == NULL)
		return "nullptr";
	if (*(DWORD*)(aux + Offsets::BuffManager::name) == NULL)
		return "nullptr";
	return (char*)(aux + Offsets::BuffManager::name);
}

buff_hash Buff::GetHash()const noexcept
{
	DWORD buff_script = *(DWORD*)(this + Offsets::BuffManager::script);
	return *(buff_hash*)(buff_script + Offsets::BuffManager::hash_name);
}