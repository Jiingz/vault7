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
		//Initates a new ImGui frame and starts the rendering.Drawings should be called after this.
		void StartRendering();
		//renders the drawings and ends the frame
		void EndRendering();

		//returns the renderer struct which contains info like the window, origin windowproc etc.
		Renderer* GetHookInfo();

	public:
		static bool initialized_;

	private:
		void SetContext();
		void SetImGui();



		std::unique_ptr<Renderer> renderer_;
	};
}