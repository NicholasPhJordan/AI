#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
   /// <param name="maxForce">The largest the magnitude of the force vector can be</param>
    Enemy(float x, float y, float collisionRadius, const char* spriteFilePath,
        Actor* target, float helath = 1, float damage = 1, float maxSpeed = 1, float maxForce = 1);

    void update(float deltatime) override;
    virtual Actor* getTarget() { return m_target; }
    virtual void setTarget(Actor* owner) { m_target = owner; }

private:
    Actor* m_target;
};

