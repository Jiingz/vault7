#pragma once
#include <core/features/feature_interface.h>
#include <core/event/event_bus.h>
#include <core/event/events.h>
namespace feature
{
	class Orbwalker : protected IFeature
	{
	public:

		enum orbwalker_state
		{
			attacking,
			moving,
			inactive
		};

		void Initialize();
		void DrawMenu();
		void SaveConfig();

		orbwalker_state GetOrbwalkerState() noexcept;

		void OnTick();
		void OnDraw();
		void OnBasicAttack(event::OnBasicAttackArgs args);
	private:

		void LoadConfig();


		float last_aa_;
		float last_move_;
		float windup_;
		orbwalker_state orbwalker_state_;

	protected:
		virtual bool CanAttack();
		virtual bool CanMove();

	};
}