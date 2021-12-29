#pragma once
#include <core/features/feature_interface.h>
#include <core/event/event_bus.h>
namespace feature
{
	class Orbwalker : protected IFeature
	{
	public:
		void Initialize();
		void OnTick();

	private:
		//Executes the OnTick routine
		static void Execute();

		float last_aa_;
		float last_move_;

	protected:
		virtual bool CanAttack();
		virtual bool CanMove();
	};
}