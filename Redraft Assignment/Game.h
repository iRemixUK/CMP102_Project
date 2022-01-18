#pragma once
#include "Player.h"
#include "Throw.h"
#include <cstdlib>
#include <ctime> // for time functions
class Game
{
private:
	int Joe_GameWins;
	int Sid_GameWins;
	int Joe_SetWins;
	int Sid_SetWins;
	int First;
	float MatchWins[14]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Total match wins array, which will be used to record how much wins each player got and to calculate the frequency

public:
	Game();
	void WhoGoesFirst(); // Function to see who goes first
	bool play_game(); // Function to play one game
	bool play_set(); // Function to play one set 
	void play_match(); // Function to play one match
	void output(); // Function to calculate the frequency

	Throw Throw;
	Player Joe;
	Player Sid;
};


