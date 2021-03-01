#include "SeekBehavior.h"
#include "Agent.h"

MathLibrary::Vector2 SeekBehavior::calculateForce(Agent* owner)
{
	//do seek behavior
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(m_target->getWorldPosition() - owner->getWorldPosition());

	return MathLibrary::Vector2();
}