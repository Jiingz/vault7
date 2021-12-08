#include <core/drawings/draw_factory.h>
#include <core/locator.h>
using namespace core;

bool DrawFactory::initialized_;

//Initializes a unique_ptr to the renderer struct
DrawFactory::DrawFactory()
{
	this->renderer_ = std::make_unique<Renderer>();
}

void DrawFactory::InitializeRenderer(IDXGISwapChain* swap_chain)
{
	if (this->renderer_->swap_chain_)
	{
		return;
	}
	if (!SUCCEEDED(swap_chain->GetDevice(__uuidof(ID3D11Device), (void**)&this->renderer_->device_)))
	{
		return;
	}
	this->renderer_->swap_chain_ = swap_chain;

	SetContext();
	SetImGui();
	initialized_ = true;
}

//Sets the renderer context (initializes swap chain, device etc)
void DrawFactory::SetContext()
{
	this->renderer_->device_->GetImmediateContext(&this->renderer_->context_);
	DXGI_SWAP_CHAIN_DESC sd;
	this->renderer_->swap_chain_->GetDesc(&sd);
	this->renderer_->window_ = sd.OutputWindow;
	ID3D11Texture2D* pBackBuffer;
	this->renderer_->swap_chain_->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	this->renderer_->device_->CreateRenderTargetView(pBackBuffer, NULL, &this->renderer_->target_view_);
	pBackBuffer->Release();
	this->renderer_->wnd_proc_ = (WNDPROC)SetWindowLongPtr(this->renderer_->window_, GWLP_WNDPROC, (LONG_PTR)this->renderer_->wnd_proc_);
}

//Creates ImGui Context and initiates all needed sources.
void core::DrawFactory::SetImGui()
{
	ImGui::CreateContext();

	ImGui_ImplWin32_Init(this->renderer_->window_);
	ImGui_ImplDX11_Init(this->renderer_->device_, this->renderer_->context_);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	io.Fonts->AddFontFromFileTTF(("C:\\Windows\\Fonts\\Candara.ttf"), 13.0f);
	io.Fonts->TexGlyphPadding = 1;
	for (auto n = 0; n < io.Fonts->ConfigData.Size; n++)
	{
		auto* const font_config = static_cast<ImFontConfig*>(&io.Fonts->ConfigData[n]);
		font_config->RasterizerMultiply = 0.8f;
		font_config->OversampleH = 4;
		font_config->OversampleV = 3;
	}
	ImGui::GetIO().Fonts->Build();

	//ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_NoMouse;
	ImGui::GetStyle().AntiAliasedFill = true;
	ImGui::GetStyle().AntiAliasedLines = true;
}
