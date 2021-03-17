#pragma once
#include "Enemy.h"

class WanderBehavior;
class PursueBehavior;
class Evadeehavior;

class ComplexEnemy : public Enemy
{
public:
	using Enemy::Enemy;
	void start() override;
	void setTarget(Actor* target) override;
	void onCollision(Actor* other) override;
	void update(float deltatime) override;

	WanderBehavior* getWander() { return m_wanderBehavior; }
	//PursueBehavior* getPurse() { return m_pursueBehavior; }
	//EvadeBehavior* getEvade() { return m_evadeBehavior; }

	bool checkTargetInSight(float angle = 2);
	bool checkTargetInRange(float range);

private:
	WanderBehavior* m_wanderBehavior;
	PursueBehavior* m_pursueBehavior;
	Evadeehavior* m_evadeBehavior;
};

