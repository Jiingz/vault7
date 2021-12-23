#include <Windows.h>
#include <core/features/feature_controller.h>

using namespace feature;

std::unique_ptr<Orbwalker> FeatureController::s_orbwalker_;

void feature::FeatureController::LoadFeatures()
{
	GetOrbwalker()->Initialize();
}

Orbwalker* feature::FeatureController::GetOrbwalker()
{
	if (!s_orbwalker_)
	{
		s_orbwalker_ = std::make_unique<Orbwalker>();
	}

	return s_orbwalker_.get();
}
