#include "Enemy.h"

sf::Texture* Enemy::texture;

Enemy::Enemy(Director& d) :
	Targetor(d)
{
	setTexture(*texture);
	
	health = 100.0f;
	mass = 2.0f;
}

void Enemy::bump(const sf::Vector2f& force)
{
	motion.velocity += force;
}

void Enemy::damage(float amount)
{
	health -= amount;
	if (health < 0)
		health = 0;
}

void Enemy::endStep(const sf::Time& time)
{
}

Enemy::~Enemy(void)
{
}