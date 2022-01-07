#include <Windows.h>
#include "callbacks.h"
#include <core/locator.h>
#include <DirectXMath.h>
#include <core/event/events.h>;
#include <mutex>
#include <core/drawings/menu/menu.h>
#include <core/mouse.h>
#include <core/drawings/permashow.h>
#include <core/tests/test_run.h>

using namespace core;
std::once_flag initMenu;
bool open;

HRESULT __stdcall Callbacks::HookedPresent(IDXGISwapChain* swap_chain, UINT sync_interval, UINT flags)
{
	if (!DrawFactory::initialized_)
	{
		core::Locator::GetDrawFactory()->InitializeRenderer(swap_chain);
	}

	core::Locator::GetDrawFactory()->StartRendering();

	core::Locator::GetEventBus()->Publish<event::OnTick>({});

	MainMenu::DrawMenu();
	core::TestRun::DrawMenu();
	PermaShow::DrawPermaShow();

	core::Locator::GetDrawFactory()->EndRendering();

	return Locator::GetHookingService()->GetOriginalPresent()(swap_chain, sync_interval, flags);
}

int __fastcall Callbacks::HookedOnProcessSpell(void* spell_book, void* edx, ActiveSpell* active_spell)
{
	event::OnProcessSpellArgs ops_args;
	ops_args.active_spell = active_spell;
	ops_args.spell_book = spell_book;
	core::Locator::GetEventBus()->Publish<event::OnProcessSpellArgs>(ops_args);

	if (active_spell->is_basic_attack || active_spell->is_special_attack || active_spell->is_headshot_attack)
	{
		event::OnBasicAttackArgs on_basic_attack_args;
		on_basic_attack_args.active_spell = active_spell;
		on_basic_attack_args.sender_index = active_spell->sender_index;
		on_basic_attack_args.is_special_attack = active_spell->is_special_attack || active_spell->is_headshot_attack;
		on_basic_attack_args.target_index_vector = active_spell->GetTargetsIndexVector();
		core::Locator::GetEventBus()->Publish<event::OnBasicAttackArgs>(on_basic_attack_args);
	}



	return Locator::GetHookingService()->GetOriginalOnProcessSpell()(spell_book, active_spell);
}

constexpr auto origin = &GetCursorPos;
BOOL WINAPI Callbacks::HookedGetCursorPos(LPPOINT lpPoint)
{
	auto org = origin(lpPoint);

	if (Mouse.enabled)
	{
		//	Mouse.mutex.lock();
		//	lpPoint->x = Mouse.x;
		//	lpPoint->y = Mouse.y;
		//	Mouse.mutex.unlock();
	}
	return org;
}