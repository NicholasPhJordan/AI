//#include "WanderBehavior.h"
//#include "Agent.h"
//
//WanderBehavior::WanderBehavior()
//{
//	m_wanderForce = 1;
//	m_forwardDistance = 1;
//}
//
//WanderBehavior::WanderBehavior(float wanderForce, float forwardDistance)
//{
//	m_wanderForce = m_wanderForce;
//	m_forwardDistance = forwardDistance;
//}

//MathLibrary::Vector2 WanderBehavior::calculateForce(Agent* owner)
//{
//	//calculate current direction and scale it
//	MathLibrary::Vector2 direction = owner->getVelocity() * m_forwardDistance;
//	//use random number generator to get a wander angle 
//	int randomNum = rand() % 500 + 1;
//	MathLibrary::Vector2 wanderAngle = {randomNum, randomNum};
//	//add to get displacement which is the wanderforce  
//	MathLibrary::Vector2 displacement = direction + wanderAngle;
//
//	return MathLibrary::Vector2();
//}

//void WanderBehavior::update(Agent* owner, float deltatime)
//{
//	//if owner isn't null, calculate new force and add it to owner
//	if (owner)
//		owner->addForce(calculateForce(owner));
//}
