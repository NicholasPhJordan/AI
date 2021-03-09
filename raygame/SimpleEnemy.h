#pragma once
#include "Enemy.h"

enum EnemyState
{
	WANDER,
	SEEK
};

class WanderBehavior;
class SeekBehavior;

class SimpleEnemy : public Enemy
{
	SimpleEnemy();

	using Enemy::Enemy;
	bool cheackTargetInSight();

	void onCollision(Actor* other) override;
	void start() override;
	void update(float deltatime) override;

	void setTarget(Actor* target) override;


private:
	EnemyState m_currentState;
	WanderBehavior* m_wander;
	SeekBehavior* m_seek;

};

