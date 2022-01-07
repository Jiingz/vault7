#include <Windows.h>

#include <core/game/game_objects/game_object.h>
#include <core/utilities.h>
#include <core/locator.h>


float GameObject::GetPercentageHealth() const
{
	return 0.0f;
}

AIManager* game::GameObject::GetAIManager()
{
	typedef AIManager* (__thiscall* OriginalFn)(PVOID);
	return core::utilities::CallVirtual<OriginalFn>(this, 149)(this);
}

float game::GameObject::GetDistanceTo(GameObject* unit)
{
	return this->position.DistanceTo(unit->position);
}

bool game::GameObject::IsInRange(float range)
{
	this->GetDistanceTo(local_player) < range;
}

bool __thiscall game::GameObject::CompareObjectTypeFlags(object_flag flag)
{
	unsigned __int8* obj = (unsigned __int8*)this;
	unsigned int v3; // edx
	unsigned int v4; // esi
	int* v5; // ecx
	int v6; // eax
	unsigned __int8 v7; // al
	unsigned int v8; // eax
	unsigned __int8* v9; // edx
	char v10; // cl
	int v12; // [esp+8h] [ebp-4h]

	v3 = 0;
	v4 = obj[81];
	v12 = *(DWORD*)&obj[4 * obj[88] + 92];
	if (v4)
	{
		v5 = (int*)(this + 84);
		do
		{
			v6 = *v5++;
			*(&v12 + v3++) ^= ~v6;
		} while (v3 < v4);
	}
	v7 = obj[82];
	if (v7)
	{
		v8 = 4 - v7;
		if (v8 < 4)
		{
			v9 = &obj[v8 + 84];
			do
			{
				v10 = *v9++;
				*((BYTE*)&v12 + v8++) ^= ~v10;
			} while (v8 < 4);
		}
	}
	return (v12 & flag) != 0;
}
