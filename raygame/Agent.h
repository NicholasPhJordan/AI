#pragma once
#include "Actor.h"
#include <vector>

class Behavior;

class Agent :
	public Actor
{
public:
    ~Agent();
    Agent();
    /// <param name="x">Position on the x axis</param>
   /// <param name="y">Position on the y axis</param>
   /// <param name="icon">The symbol that will appear when drawn</param>
   /// <param name="maxForce">The largest the magnitude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
   /// <param name="maxForce">The largest the magnitude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
   /// <param name="maxForce">The largest the magnitude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce);

    void update(float deltatime);

    float getMaxForce() { return m_maxForce; }
    void setMaxForce(float maxForce) { maxForce = m_maxForce; }

    //add given force to total force that is being applied to agent
    void addForce(MathLibrary::Vector2 force);
    void addBehavior(Behavior* behavior);

    template<typename BehaviorType>
    BehaviorType* getBehavior();

private:
    MathLibrary::Vector2 m_force;
    float m_maxForce;
    std::vector<Behavior*> m_behaviors;
};

template<typename BehaviorType>
inline BehaviorType* Agent::getBehavior()
{
    //iterate through list of behaviors 
    for (int i = 0; i < m_behaviors.size(); i++)
    {
        //attempt to cast behavior at the current index of given type
        BehaviorType* behavior = dynamic_cast<BehaviorType*>(m_behaviors[i]);

        //if cast is unsuccessful return behavior found
        if (behavior)
            return behavior;
    }
    //if no behaviors found to match the type, return nullptr
    return NULL;
}
