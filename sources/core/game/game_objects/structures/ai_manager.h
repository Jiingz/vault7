#pragma once
#include <core/game/Offsets.h>
#include <core/drawings/geometry/vector.h>

namespace game
{
	class AIManager
	{
	public:
		union
		{

			DEFINE_MEMBER_N(Vector3 waypoint, Offsets::WayPoint);
			DEFINE_MEMBER_N(void* navmesh, Offsets::NavMesh); //should point to NavMesh class. TODO
			DEFINE_MEMBER_N(float moveSpeed, Offsets::MoveSpeed);
			DEFINE_MEMBER_N(bool is_moving, Offsets::IsMoving);
			DEFINE_MEMBER_N(int32_t passed_waypoint_count, Offsets::PassedWayPoints);
			DEFINE_MEMBER_N(Vector3 nav_begin, Offsets::NavBegin);
			DEFINE_MEMBER_N(Vector3 nav_end, Offsets::NavEnd);
			DEFINE_MEMBER_N(float dash_speed, Offsets::DashSpeed);
			DEFINE_MEMBER_N(bool is_dashing, Offsets::IsDashing);
			DEFINE_MEMBER_N(Vector3 server_pos, Offsets::ServerPos);
			DEFINE_MEMBER_N(Vector3 velocity, Offsets::Velocity);
			DEFINE_MEMBER_N(bool is_dashing_raw, Offsets::IsDashingRaw);
		};
	};
}