#include <Windows.h>
#include <core/features/orbwalker.h>
#include <core/locator.h>
#include <core/event/events.h>
#include <core/features/feature_controller.h>
#include <core/features/humanizer.h>
#include <string>
#include <core/drawings/menu/menu.h>
#include <core/sdk/controller.h>
#include <core/game/world/world.h>

using namespace feature;

SetOnTick(GetOnTick, feature::FeatureController::GetOrbwalker()->OnTick)
SetOnDraw(GetOnDraw, feature::FeatureController::GetOrbwalker()->OnDraw)
SetOnBasicAttack(GetOnBasicAttack, feature::FeatureController::GetOrbwalker()->OnBasicAttack)

void Orbwalker::Initialize()
{
	core::Locator::GetEventBus()->Subscribe<event::OnTick>(&GetOnTick);
	core::Locator::GetEventBus()->Subscribe<event::OnTick>(&GetOnDraw);
	core::Locator::GetEventBus()->Subscribe<event::OnBasicAttackArgs>(&GetOnBasicAttack);

	core::Locator::GetGameComponents()->PrintChat("Orbwalker++ Loaded");

	LoadConfig();
}

void feature::Orbwalker::DrawMenu()
{
	ImGui::SetCursorPos({ 144.f,48.f });
	ImGui::PushItemWidth(531.000000);
	ImGui::SliderFloat("windup", &this->windup_, 0, 90);
	ImGui::PopItemWidth();
}

bool Orbwalker::CanAttack()
{
	if (local_player->character_data->hash_name == game::hash_name::Jhin)
	{
		if (local_player->buff_manager.GetBuffEntryByName("JhinPassiveReload"))
			return false;
	}

	return GetTickCount() + 20 / 2.f >= Orbwalker::last_aa_ + local_player->GetAttackDelay() * 1000.f;
}

bool Orbwalker::CanMove()
{
	return GetTickCount() >= Orbwalker::last_aa_ + local_player->GetAttackCastDelay() * 1000.f + 20 / 2 + Orbwalker::windup_;
}

void Orbwalker::OnTick()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		Hero* target = sdk::TargetSelector::GetBestTarget();

		if (target && Orbwalker::CanAttack())
		{
			sdk::Controller::Attack(target);
			this->orbwalker_state_ = orbwalker_state::attacking;
		}
		else if (Orbwalker::CanMove() && Orbwalker::last_move_ < GetTickCount())
		{
			this->orbwalker_state_ = orbwalker_state::moving;

			Vector3 mousePos = core::Locator::GetGameComponents()->GetMouseWorldPos();
			sdk::Controller::Move(&mousePos);
			Orbwalker::last_move_ = GetTickCount() + 20;
		}
	}
	else
	{
		this->orbwalker_state_ = orbwalker_state::inactive;
	}
}


void Orbwalker::OnDraw()
{
	core::Locator::GetDrawFactory()->draw_circle(local_player->position, local_player->attack_range + local_player->GetBoundingRadius(), ImColor{ 217,144,7,255 }, core::DrawFactory::DrawType::Normal, 1.f);
}

void feature::Orbwalker::OnBasicAttack(event::OnBasicAttackArgs args)
{
	if (args.sender_index != local_player->index)
		return;

	last_aa_ = GetTickCount() - 20 / 2;
}

void feature::Orbwalker::SaveConfig()
{
	core::Locator::config.Write<float>("windup", this->windup_);
}

Orbwalker::orbwalker_state feature::Orbwalker::GetOrbwalkerState() noexcept
{
	return this->orbwalker_state_;
}


void feature::Orbwalker::LoadConfig()
{
	this->windup_ = core::Locator::config.Read<float>("windup");
}
