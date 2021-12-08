#pragma once

namespace Features
{
	class IFeature
	{
	protected:
		/// <summary>
		/// Initializes the feature, called once on start.
		/// </summary>
		virtual void Initialize() = 0;

		/// <summary>
		/// Called every Frame.
		/// </summary>
		virtual void OnTick() = 0;
	};
}