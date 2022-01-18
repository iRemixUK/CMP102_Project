#pragma once
#include <string>
#include <iostream>
using namespace std;
class Player
{
private:
	int successrate;
	int score;

public:
	Player(); // When called will set the players name and successrate
	void set_SuccessRate(int successrate); // Sets the player's successrate
	int get_SuccessRate(); // Gets the player's successrate
	void set_score(int s); // Function to set the current score of the game
	int get_score(); // Function to get the current score of the game
	void minus_score(int minus); // Function to minus the score when the player hits the dartboard
};
