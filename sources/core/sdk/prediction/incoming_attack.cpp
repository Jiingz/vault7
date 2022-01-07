#include <core/sdk/prediction/incoming_attack.h>

sdk::prediction::IncomingAttack::IncomingAttack(AttackableUnit* source, AttackableUnit* target, Vector3 sourcePosition, float delay, float animationTime, float missileSpeed, float startTime, float endTime, float damage, ActiveSpell* attack)
{
	this->atk = attack;
	this->source = source;
	this->target = target;
	this->source_position = sourcePosition;
	this->delay = delay;
	this->animation_delay = animationTime;
	this->missile_speed = missileSpeed;
	this->start_time = startTime;
	this->end_time = endTime;
	this->damage = damage;
	this->processed = false;
}
