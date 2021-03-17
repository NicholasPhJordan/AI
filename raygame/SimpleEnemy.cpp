#include "SimpleEnemy.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"

bool SimpleEnemy::cheackTargetInSight()
{
	//chack if target is null, if so return false
	if (getTarget() == nullptr)
		return false;

	//find the direction vector that the represetns where the target is relative to the enemy
	float targetPosition = (getTarget()->getWorldPosition() - getWorldPosition()).getMagnitude();
	//find dot product of the enemy's forward and the direction vector 
	
	//find the angle using the dot product

	//check if that angle is greater than the enemy's viewing angle(any value you see fit is fine)

	//return if the enemy saw the target
	
	return false;
}

void SimpleEnemy::onCollision(Actor* other)
{
	//Actor* player;
	//Actor* player;
	//check to see if enemy ran into player
	//if (other == player)
	//{
	//	//if enemy has run into player, deal damage to the player
	//	//player.takeDamage(getDamage());
	//	//if the player's health is less than 0, set the target to be nullptr
	//	//if (player.getHealth())
	//}
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

void SimpleEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_seek->setTarget(target);
}