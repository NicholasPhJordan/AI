#include "SeekBehavior.h"
#include "Agent.h"
#include "Actor.h"

SeekBehavior::SeekBehavior()
{
	m_target = nullptr;
	setForceScale(1);
}

SeekBehavior::SeekBehavior(Actor* target, float seekForce)
{
	m_target = target;
	setForceScale(seekForce);
}

MathLibrary::Vector2 SeekBehavior::calculateForce(Agent* owner)
{
	//find the direction to move in
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(m_target->getWorldPosition() - owner->getWorldPosition());
	//scale the direction vector by the seekForce
	MathLibrary::Vector2 desiredVelocity = direction * getForceScale();
	//subtract current velocity by desired velocity to find seekForce
	MathLibrary::Vector2 steeringForce = desiredVelocity - owner->getVelocity();

	return steeringForce;
}

void SeekBehavior::update(Agent* owner, float deltatime)
{
	//if owner isn't null, calculate new force and add it to owner (owner and agent are the same thing)
	if (owner)
		owner->addForce(calculateForce(owner));
}
