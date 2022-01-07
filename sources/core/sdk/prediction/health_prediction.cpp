#include <Windows.h>
#include <core/sdk/prediction/health_prediction.h>
#include <core/sdk/prediction/incoming_attack.h>
#include <core/locator.h>
using namespace sdk::prediction;

void HealthPrediction::Initialize()
{
	core::Locator::GetEventBus()->Subscribe<event::OnBasicAttackArgs>(CacheAttacks);
}

void sdk::prediction::HealthPrediction::CacheAttacks(event::OnBasicAttackArgs args)
{
	auto caster = core::Locator::GetWorld()->GetAttackableUnits().at(args.sender_index);

	if (caster->team != local_player->team || !caster->IsInRange(2000.f))
		return;

	auto target = core::Locator::GetWorld()->GetAttackableUnits().at(args.target_index_vector[0]);
}
