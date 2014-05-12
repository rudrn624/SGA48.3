#include "enemy.h"

Enemy::Enemy()
: dx(1)
{
}
void Enemy::Update()
{
}
void Enemy::Draw(char* board)
{
}
Enemy& Enemy::operator >> (char* board)
{
	return *this;
}

