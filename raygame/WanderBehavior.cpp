#include "WanderBehavior.h"
#include "Agent.h"
#include "Actor.h"

WanderBehavior::WanderBehavior(float circleDistance, float circleRadius)
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;
}

MathLibrary::Vector2 WanderBehavior::getRandomPosition()
{
	int rando = rand() % 760 + 1;
	int rando2 = rand() % 760 + 1;
	MathLibrary::Vector2 randPosition = MathLibrary::Vector2(cos(rando), sin(rando2));
	return randPosition;
}

MathLibrary::Vector2 WanderBehavior::calculateForce(Agent* owner)
{
	MathLibrary::Vector2 facing = owner->getVelocity();
	facing.getNormalized();
	MathLibrary::Vector2 circleLocation = facing * m_circleDistance;
	MathLibrary::Vector2 displacement = getRandomPosition() * m_circleRadius;
	MathLibrary::Vector2 wanderForce = displacement + circleLocation;
	return wanderForce;
}

void WanderBehavior::update(Agent* owner, float deltatime)
{
	if (owner)
		owner->addForce(calculateForce(owner));
}
