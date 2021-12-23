#include <Windows.h>
#include <core/features/orbwalker.h>
#include <core/locator.h>
#include <core/event/events.h>
#include <functional>
#include <core/features/feature_controller.h>
#include <string>

using namespace feature;

void Orbwalker::Initialize()
{
	core::Locator::GetGameComponents()->PrintChat("Orbwalker++ Loaded");
	core::Locator::GetEventBus()->Subscribe<event::OnTick>(Execute);

	this->last_aa_ = 0.f;
}

void Orbwalker::Execute()
{
	FeatureController::GetOrbwalker()->OnTick();
}

bool Orbwalker::CanAttack()
{
	return GetTickCount64() + 20 / 2.f >= this->last_aa_ + core::Locator::GetWorld()->GetPlayer()->GetAttackDelay() * 1000.f;
}

bool Orbwalker::CanMove()
{
	return GetTickCount64() >= this->last_aa_ + core::Locator::GetWorld()->GetPlayer()->GetAttackDelay() * 1000.f;
}

void Orbwalker::OnTick()
{
	Hero* target = GetBestTarget();
	if(target)
	core::Locator::GetGameComponents()->PrintChat(std::to_string(target->health).c_str());
}
