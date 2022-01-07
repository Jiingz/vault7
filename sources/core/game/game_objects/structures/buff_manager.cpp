#include <Windows.h>
#include <core/game/game_objects/structures/buff_manager.h>

using namespace game;

Buff* BuffManager::GetBuffEntryByName(const char* BuffName) const
{
	for (DWORD buff_ptr = start; buff_ptr != end; buff_ptr += 0x8)
	{
		Buff* buff = *(Buff**)buff_ptr;
		if (!buff->IsValid())
			continue;
		if (buff->IsAlive())
		{
			if (strcmp(buff->GetName(), BuffName) == 0)
				return buff;
		}
	}
	return nullptr;
}

Buff* BuffManager::GetBuffEntryByHash(buff_hash hash)
{
	for (DWORD buff_ptr = start; buff_ptr != end; buff_ptr += 0x8)
	{
		Buff* buff = *(Buff**)buff_ptr;
		if (!buff->IsValid())
			continue;
		if (buff->IsAlive())
		{
			if (hash == buff->GetHash())
				return buff;
		}
	}
	return nullptr;
}

std::vector<Buff*> game::BuffManager::GetBuffEntries()
{
	std::vector<Buff*> buff_entries;
	for (DWORD pBuffPtr = start; pBuffPtr != end; pBuffPtr += 0x8)
	{
		Buff* pBuff = *(Buff**)pBuffPtr;
		if (!pBuff->IsValid())
			continue;
		if (pBuff->IsAlive())
		{
			buff_entries.push_back(pBuff);
		}
	}
	return buff_entries;
}
