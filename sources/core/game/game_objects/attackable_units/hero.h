#pragma once
#include <attackable_units/AttackableUnit.h>

class Hero : public AttackableUnit
{
public:
	void IssueOrder(AttackableUnit* target);
	void IssueOrder(Vector3* move_pos);
};

