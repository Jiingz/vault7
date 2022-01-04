#include <Windows.h>
#include <core/game/game_objects/structures/buff_manager.h>

using namespace game;

Buff* BuffManager::GetBuffEntryByName(const char* BuffName) const
{
	for (DWORD pBuffPtr = start; pBuffPtr != end; pBuffPtr += 0x8)
	{
		Buff* pBuff = *(Buff**)pBuffPtr;
		if (!pBuff->IsValid())
			continue;
		if (pBuff->IsAlive())
		{
			if (strcmp(pBuff->GetName(), BuffName) == 0)
				return pBuff;
		}
	}
	return nullptr;
}

Buff* BuffManager::GetBuffEntryByHash(buff_hash hash)
{
	for (DWORD pBuffPtr = start; pBuffPtr != end; pBuffPtr += 0x8)
	{
		Buff* pBuff = *(Buff**)pBuffPtr;
		if (!pBuff->IsValid())
			continue;
		if (pBuff->IsAlive())
		{
			if (hash == pBuff->GetHash())
				return pBuff;
		}
	}
	return nullptr;
}