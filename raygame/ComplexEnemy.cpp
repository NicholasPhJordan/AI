#include "ComplexEnemy.h"
#include "WanderBehavior.h"
//include PurseBehavior
//include EvadeBehavior
#include "Player.h"

void ComplexEnemy::start()
{
	Enemy::start();

	//initialize behaviors
	m_wanderBehavior = getBehavior<WanderBehavior>();
	//m_pursueBehavior = getBehavior<PursueBehavior>();
	//m_evadeBehavior = getBehavior<EvadeBehavior>();

	//set target to target given from the base class
	setTarget(Enemy::getTarget());
}

void ComplexEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	//m_purseBehavior->setTarget(target);
	//m_evadeBehavior->setTarget(target);
}

void ComplexEnemy::onCollision(Actor* other)
{
	Enemy::onCollision(other);

	Player* player = dynamic_cast<Player*>(other);

	//if the actor is a player, damage it
	if (player)
	{
		player->takeDamage(getDamage());

		//if the player has died, set target to be null
		if (player->getHealth() <= 0)
		{
			setTarget(nullptr);
		}
	}
}
