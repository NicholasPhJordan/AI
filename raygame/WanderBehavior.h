#pragma once
#include "SteeringBehavior.h"

class Actor;

class WanderBehavior : public SteeringBehavior
{
public:
	WanderBehavior();
	WanderBehavior(float CircleDistance, float circleRadius);
	MathLibrary::Vector2 getRandomPosition();
	MathLibrary::Vector2 calculateForce(Agent* owner) override;
	void update(Agent* owner, float deltatime) override;

private:
	float m_circleDistance;
	float m_circleRadius;
};

