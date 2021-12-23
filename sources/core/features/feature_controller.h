#pragma once
#include <memory>
#include <core/features/orbwalker.h>

namespace feature
{
	//controller class for all features
	class FeatureController
	{
	public:
		static void LoadFeatures();
		static Orbwalker* GetOrbwalker();

	private:
		static std::unique_ptr<Orbwalker> s_orbwalker_;
	};
}