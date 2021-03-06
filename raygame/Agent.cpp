#include "Agent.h"
#include "Behavior.h"

Agent::~Agent() {}

Agent::Agent() : Actor()
{
	m_force = { 0, 0 };
	m_maxForce = 1;
}

Agent::Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, icon, maxSpeed)
{
	m_force = { 0, 0 };
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, sprite, maxSpeed)
{
	m_force = { 0, 0 };
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, spriteFilePath, maxSpeed)
{
	m_force = { 0, 0 };
	m_maxForce = maxForce;
}

void Agent::update(float deltatime)
{
	//reset force to be zero
	m_force = { 0,0 };

	//call update for each behavior in the list
	for(int i = 0; i < m_behaviors.size(); i++)
		m_behaviors[i]->update(this, deltatime);

	//updates velocity with the new force
	setVelocity(getVelocity() + m_force * deltatime);

	//rotates agent to face the direction it's moving
	updateFacing();

	Actor::update(deltatime);
}

void Agent::addForce(MathLibrary::Vector2 force)
{
	//add given force to total force
	m_force = m_force + force;

	//if total force is greater than maxforce, set magnitude to be maxForce
	if(m_force.getMagnitude() > getMaxForce())
		m_force = m_force.getNormalized() * getMaxForce();
}

void Agent::addBehavior(Behavior* behavior)
{
	if (behavior)
		m_behaviors.push_back(behavior);
}
