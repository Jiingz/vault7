#pragma once

namespace game
{
	enum game_object_team : int32_t
	{
		Order = 100,
		Chaos = 200,
		Neutral = 300
	};

	enum recall_state : int32_t
	{
		twisted_fate_teleport = 4,
		recalling = 6,
		recall_yuumi_attached = 10,
		super_recall = 11,
		teleporting = 16,
		ShenStandUnitedState = 19
	};

	enum visible_type : int32_t
	{
		visible = 0,
		local_visible = 1,
		force_visible = 8
	};

	enum combat_type : int32_t
	{
		melee = 1,
		ranged = 2
	};

}