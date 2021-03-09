#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(float x, float y, float collisionRadius, const char* spriteFilePath, :
Character)
{
	setTarget(target);
}

void Enemy::update(float deltatime)
{
	Character::update(deltatime);

	//checks if enemy goes outside screen bounds and replaces the om hte other side 
	//ENEMY GO TELEPORT
	if (getWorldPosition().x > Game::getScreenWidth() / 32)
		setWorldPostion(MathLibrary::Vector2(0, getWorldPosition().y));
	if (getWorldPosition().x < 0)
		setWorldPostion(MathLibrary::Vector2(Game::getScreenWidth() / 32, getWorldPosition().y));
	if (getWorldPosition().y > Game::getScreenHeight() / 32)
		setWorldPostion(MathLibrary::Vector2(0, getWorldPosition().x));
	if (getWorldPosition().y < 0)
		setWorldPostion(MathLibrary::Vector2(Game::getScreenHeight() / 32, getWorldPosition().x));
}
