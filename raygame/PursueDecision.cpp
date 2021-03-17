#include "PursueDecision.h"
#include "ComplexEnemy.h"

void PursueDecision::makeDecision(Agent* agent, float deltatime)
{
	ComplexEnemy* enemy = dynamic_cast<ComplexEnemy*>(agent);

	if (enemy)
	{
		//enemy->getPurse()->setEnabled(true);
		//enemy->getWander()->setEnabled(false);
		//enemy->getEvade()->setEnabled(flase);
	}
}
