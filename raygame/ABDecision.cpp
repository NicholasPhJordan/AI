#include "ABDecision.h"

ABDecision::ABDecision(Decision* leftChild, Decision* rightChild)
{
	m_leftChild = leftChild;
	m_rightChild = rightChild;
}

void ABDecision::makeDecision(Agent* agent, float deltatime)
{
	//call the checkDecision function for this decision
	if (checkCondition(agent, deltatime))
	{
		//if the function returns true and the child isn't null, move to the left node
		if (m_leftChild)
			m_leftChild->makeDecision(agent, deltatime);
	}
	else
	{
		//if the function returns true and the child isn't null, move to the right node
		if (m_rightChild)
			m_rightChild->makeDecision(agent, deltatime);
	}
}
