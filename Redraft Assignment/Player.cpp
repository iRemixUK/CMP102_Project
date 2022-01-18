#include "Player.h"

Player::Player()
{
}

void Player::set_SuccessRate(int SuccessRate)
{
	successrate = SuccessRate;
}

int Player::get_SuccessRate()
{
	return successrate;
}

void Player::set_score(int s)
{
	score = s;
}
int Player::get_score()
{
	return score;
}

void Player::minus_score(int minus)
{
	score = score - minus;
}