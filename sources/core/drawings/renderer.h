#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

struct Renderer
{
public:
	HWND window_;
	IDXGISwapChain* swap_chain_;
	ID3D11RenderTargetView* target_view_;
	WNDPROC wnd_proc_;
	ID3D11Device* device_;
	ID3D11DeviceContext* context_;
};