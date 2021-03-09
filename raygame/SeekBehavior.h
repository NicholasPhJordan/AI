#pragma once
#include "SteeringBehavior.h"

class Actor;

class SeekBehavior : public SteeringBehavior
{
public:
	SeekBehavior();
	SeekBehavior(Actor* target, float seekForce = 1);

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

	MathLibrary::Vector2 calculateForce(Agent* owner) override;
	void update(Agent* owner, float deltatime) override;
private:
	//the agent the bahvior is seeking 
	Actor* m_target;
};

