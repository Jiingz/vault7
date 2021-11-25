#pragma once
#include <wtypes.h>
#include <core/drawings/renderer.h>
#include <memory>

namespace core
{
	class DrawFactory
	{
	public:
		DrawFactory();

		void InitializeRenderer(IDXGISwapChain* swap_chain);

	public:
		static bool initialized_;

	private:
		void SetContext();
		void SetImGui();

		std::unique_ptr<Renderer> renderer_;
	};
}