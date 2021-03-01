#include "Agent.h"

Agent::Agent() : Actor()
{
	m_force = { 0, 0 };
	m_maxForce = 1;
}

Agent::~Agent()
{

}

Agent::Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, icon, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, Sprite* sprite, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce) :
	Actor(x, y, collisionRadius, const char* spriteFilePath, maxSpeed)
{
	m_maxForce = maxForce;
}

void Agent::update(float deltatime)
{
	//reset force to be zero
	m_force = { 0,0 };

	//TO DO: Update forces

	//updates velocity with the new force
	setVelocity(getVelocity() + m_force * deltatime);

	Actor::update(deltatime)
}

void Agent::addForce(MathLibrary::Vector2 force)
{
	//add given force to total force
	m_force = m_force + force;

	//if total force is greater than maxforce, set magnitude to be maxForce
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}
}