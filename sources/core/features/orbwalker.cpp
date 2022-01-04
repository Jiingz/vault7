#include <Windows.h>
#include <core/features/orbwalker.h>
#include <core/locator.h>
#include <core/event/events.h>
#include <functional>
#include <core/features/feature_controller.h>
#include <core/features/humanizer.h>
#include <string>
#include <core/drawings/menu/menu.h>

using namespace feature;

void Orbwalker::Initialize()
{
	core::Locator::GetEventBus()->Subscribe<event::OnTick>(OnTickSub);
	core::Locator::GetEventBus()->Subscribe<event::OnBasicAttackArgs>(OnBasicAttackSub);
	core::Locator::GetGameComponents()->PrintChat("Orbwalker++ Loaded");
	this->last_aa_ = 0.f;
	this->last_move_ = 0.f;

}

void feature::Orbwalker::DrawMenu()
{
	ImGui::SetCursorPos({ 144.f,48.f });
	ImGui::PushItemWidth(531.000000);
	ImGui::SliderFloat("windup", &this->windup_, 0, 90);
	ImGui::PopItemWidth();
}


void Orbwalker::OnTickSub()
{
	FeatureController::GetOrbwalker()->OnTick();
}

void Orbwalker::OnBasicAttackSub(event::OnBasicAttackArgs args)
{
	FeatureController::GetOrbwalker()->OnBasicAttack(args);
}

bool Orbwalker::CanAttack()
{
	return GetTickCount() + 20 / 2.f >= this->last_aa_ + local_player->GetAttackDelay() * 1000.f;
}

bool Orbwalker::CanMove()
{
	return GetTickCount() >= last_aa_ + local_player->GetAttackCastDelay() * 1000.f + 20 / 2 + this->windup_;
}

void Orbwalker::OnTick()
{

	Hero* target = GetBestTarget();

	if (GetAsyncKeyState(VK_SPACE))
	{
		Hero* target = GetBestTarget();

		if (target && CanAttack())
		{
			core::Locator::GetWorld()->GetPlayer()->Attack(target);
		}
		else if (CanMove() && this->last_move_ < GetTickCount())
		{

			Vector3 mousePos = core::Locator::GetGameComponents()->GetMouseWorldPos();
			core::Locator::GetWorld()->GetPlayer()->Move(mousePos);
			this->last_move_ = GetTickCount() + 20;
		}
	}
}

void feature::Orbwalker::OnBasicAttack(event::OnBasicAttackArgs args)
{
	if (args.sender_index != local_player->index)
		return;

	this->last_aa_ = GetTickCount() - 20 / 2;
}
