#pragma once
#include <core/event/events.h>
namespace sdk::prediction
{
	static class HealthPrediction
	{
	public:
		static void Initialize();

	private:
		static void CacheAttacks(event::OnBasicAttackArgs args);
	};
}