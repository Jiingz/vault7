#pragma once
#include <core/features/feature_interface.h>
#include <core/event/event_bus.h>
#include <core/event/events.h>
namespace feature
{
	class Orbwalker : protected IFeature
	{
	public:
		void Initialize();
		void DrawMenu();
	private:
		void OnTick();
		void OnBasicAttack(event::OnBasicAttackArgs args);

		static void OnTickSub();
		static void OnBasicAttackSub(event::OnBasicAttackArgs args);

		float last_aa_;
		float last_move_;

		float windup_;

	protected:
		virtual bool CanAttack();
		virtual bool CanMove();

	};
}