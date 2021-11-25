#pragma once
#include <windef.h>
#include <stdint.h>
#include <core/memory/member.h>
#include <core/drawings/geometry/vector.h>

namespace game::gameObjects {

	class GameObject
	{
	public:
		memory::AlignedMember<Vector3, 500> position; //0x01F4


	public:
		float GetPercentageHealth() const;
	};

}

using namespace game::gameObjects;
