#pragma once
#include <core/features/feature_interface.h>

namespace Features
{
	class Orbwalker : protected IFeature
	{
	public:
		void Initialize();
	};
}