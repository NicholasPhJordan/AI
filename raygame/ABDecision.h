#pragma once
#include "Decision.h"

/// <summary>
/// Abstract class for all decisions
/// </summary>
class ABDecision : public Decision
{
public:
	ABDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);

	virtual void makeDecision(Agent* agent, float deltatime) override;

	virtual bool checkCondition(Agent* agent, float deltatime) { return false; }

private:
	Decision* m_leftChild;
	Decision* m_rightChild;
};

