#include "SimpleEnemy.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"

bool SimpleEnemy::cheackTargetInSight()
{
	//chack if target is null, if so return false

	//find the direction vector that the target 
	
	return false;
}

void SimpleEnemy::onCollision(Actor* other)
{

}

void SimpleEnemy::start()
{
	//call base start function
	Enemy::start();

	//set default state of the enemy
	m_currentState = WANDER;

	//Initialize member varibles 
	m_seek = getBehavior<SeekBehavior>();
	m_wander = getBehavior<WanderBehavior>();

	//set the target to the base class target
	setTarget(Enemy::getTarget());
}

void SimpleEnemy::update(float deltatime)
{
	//create switch statement for the state machine
	//switch should transition to the wander state if the target is not in sight 
	//You can set the wander force to be whatever value you see fit but be sure to set seek force to zero

	//switch should transition to the seek state if target is in sight 
	//you can set the seek force to be whatever value you see fit but be sure to set wanderforce to zero

	Enemy::update(deltatime);
}

void SimpleEnemy::setTarget(Actor* )