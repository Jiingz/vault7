#include <Windows.h>
#include <core/features/orbwalker.h>
#include <core/locator.h>
#include <core/event/events.h>
#include <functional>
#include <core/features/feature_controller.h>
#include <core/features/humanizer.h>
#include <string>

using namespace feature;

void Orbwalker::Initialize()
{
	core::Locator::GetGameComponents()->PrintChat("Orbwalker++ Loaded");
	core::Locator::GetEventBus()->Subscribe<event::OnTick>(Execute);

	this->last_aa_ = 0.f;
	this->last_move_ = 0.f;
}

void Orbwalker::Execute()
{
	FeatureController::GetOrbwalker()->OnTick();
}

bool Orbwalker::CanAttack()
{
	return GetTickCount() + 20 / 2.f >= this->last_aa_ + core::Locator::GetWorld()->GetPlayer()->GetAttackDelay() * 1000.f;
}

bool Orbwalker::CanMove()
{
	return GetTickCount() >= this->last_aa_ + core::Locator::GetWorld()->GetPlayer()->GetAttackCastDelay() * 1000.f + 20.f / 2 + 90.f;
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
			this->last_aa_ = GetTickCount() + 20;
		}
		else if (CanMove() && this->last_move_ < GetTickCount())
		{

			Vector3 mousePos = core::Locator::GetGameComponents()->GetMouseWorldPos();
			core::Locator::GetWorld()->GetPlayer()->Move(mousePos);
			this->last_move_ = GetTickCount() + 30;
		}
	}
}
