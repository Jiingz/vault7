#pragma once
#include <core/hooking/structs.h>
#include <vector>

namespace event
{
	struct OnTick
	{
		//Empty atm
	};

	struct OnBasicAttackArgs {
		ActiveSpell* active_spell;
		DWORD sender_index;
		bool is_special_attack;
		std::vector<short> target_index_vector;
	};

	struct RecallEvent {
		// float recall_time;
		// GameObject* caster;
	};

	struct OnProcessSpellArgs
	{
		void* spell_book;
		ActiveSpell* active_spell;
	};
}
