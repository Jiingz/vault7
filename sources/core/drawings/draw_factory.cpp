#include <core/drawings/draw_factory.h>
#include <core/locator.h>
#include <core/libs/xor.h>
#include <core/libs/ImGui/imgui_internal.h>
using namespace core;

bool DrawFactory::initialized_;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall HookedWindowProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//We need this so clicks get recognized on the ImGui UI.
LRESULT __stdcall HookedWindowProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	//	ONLY CALL IF MENU OPEN

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(core::Locator::GetDrawFactory()->GetHookInfo()->wnd_proc_, hWnd, uMsg, wParam, lParam);
}


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
	this->renderer_->wnd_proc_ = (WNDPROC)SetWindowLongPtr(this->renderer_->window_, GWLP_WNDPROC, (LONG_PTR)HookedWindowProc);

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

void core::DrawFactory::StartRendering()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("##overlay", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs);
	ImGui::SetWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiCond_Always);
}

void core::DrawFactory::EndRendering()
{
	ImGui::GetForegroundDrawList()->PushClipRectFullScreen();

	ImGui::EndFrame();
	ImGui::Render();

	this->renderer_->context_->OMSetRenderTargets(1, &this->renderer_->target_view_, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

Renderer* DrawFactory::GetHookInfo()
{
	return this->renderer_.get();
}

void core::DrawFactory::draw_circle(Vector3 position, float radius, ImColor color, DrawType type, float thickness)
{
	if ((color & IM_COL32_A_MASK) == 0)
		return;
	Vector3 world_pos(position.X, position.Y, position.Z);
	for (auto i = 0; i <= 99; i++) {
		auto angle = (float)i * IM_PI * 1.98f / 98.0f;
		world_pos.X = position.X + ImCos(angle) * radius;
		world_pos.Z = position.Z + ImSin(angle) * radius;

		Vector2 w2s;
		core::Locator::GetWorld()->WorldToScreen(&world_pos, &w2s);
		ImGui::GetWindowDrawList()->PathLineTo(ImVec2(w2s.X, w2s.Y));
	}
	if (type == DrawType::Normal)
		ImGui::GetWindowDrawList()->PathStroke(color, 0, thickness);
	else
		ImGui::GetWindowDrawList()->PathFillConvex(color);
}
