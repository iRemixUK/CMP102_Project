#include "Game.h"

Game::Game()
{
	//Joe
	Joe.set_SuccessRate(71);

	//Sid
	Sid.set_SuccessRate(73);
	
	srand(time(0)); // Setting this here so the rand function will work properly when the object is initialised
}

void Game::WhoGoesFirst()
{
	// If a player misses 50 
	int JoeThrow = 50;
	int SidThrow = 50;

	while (JoeThrow == 50 && SidThrow == 50)
	{
		JoeThrow = Throw.throw_bull(Joe.get_SuccessRate());
		SidThrow = Throw.throw_bull(Sid.get_SuccessRate());
	}

	if (JoeThrow != 50)
	{
		First = 0;
	}

	if (SidThrow != 50)
	{
		First = 1;
	}
}

bool Game::play_game()
{
	// Variables
	Joe.set_score(501);
	Sid.set_score(501);
	int score_JoeReset;
	int score_SidReset;
	int endgame = 1;
	int Joe_win = 0;
	int Sid_win = 0;
	int Even_Numbers[20] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40 }; // array for even numbers between 1-40
	int Odd_Numbers[19] = { 3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39 }; // array for odd numbers between 3-40
	
	WhoGoesFirst(); // Calling the function to see what player will start first
	
	// Infinite while loop that makes sure that a game will be completed
	while (endgame == 1)
	{
		
		if (Joe.get_score() == 0)
		{
			return true;
		}

		if (Sid.get_score() == 0)
		{
			return false;
		}
		
		// If a player bursts ie goes below zero their score will be reset to what it was before they threw their darts
		score_JoeReset = Joe.get_score();
		score_SidReset = Sid.get_score();

		// Joe's throw
		if (First == 1)
		{
			for (int darts = 0; darts < 3; darts++)
			{
				
				//If statement to break out of for loop if the score is at 0
				if (Joe.get_score() == 0)
				{
					return true;
				}

				if (Joe.get_score() > 61)
				{
					Joe.minus_score(Throw.throw_treble(20, Joe.get_SuccessRate())); // This line throws a dart at a treble 20 and will then minus the score
				}
				else if (Joe.get_score() <= 61 && Joe.get_score() > 41)
				{
					Joe.minus_score(Throw.throw_double(20));
				}
				else if (Joe.get_score() == 50)
				{
					Joe.minus_score(Throw.throw_bull(Joe.get_SuccessRate())); // This line throws a dart at the bull and will then minus the score
				}
				
				else if (Joe.get_score() <= 41)
				{
					for (int i = 0; i < 20; i++)
					{
						if (Joe.get_score() == Even_Numbers[i])
						{
							int x = Joe.get_score() / 2;
							Joe.minus_score(Throw.throw_double(x));
						}
						if (Joe.get_score() == 41)
						{
							Joe.minus_score(Throw.throw_single(1));
						}
					}

					for (int i = 0; i < 9; i++)
					{
						if (Joe.get_score() == Odd_Numbers[i])
						{
							// Strategy to get close to 2 so player can throw for a double 1 for the win
							int aim = Joe.get_score() - 2;
							aim = rand() % aim;
							Joe.minus_score(Throw.throw_single(aim));
						}
					}

					for (int i = 9; i < 19; i++)
					{
						if (Joe.get_score() == Odd_Numbers[i])
						{
							// Strategy to throw for a random odd number so a double can be thrown for a win
							int b = rand() % 9;
							Joe.minus_score(Throw.throw_single(Odd_Numbers[b]));
						}
					}
				}

				if (Joe.get_score() == 1 || Joe.get_score() < 0)
				{
					// Resets score if the player gets a 1 or below
					Joe.set_score(score_JoeReset);
					darts = 3;
				}

				if (Joe.get_score() == 0)
				{
					return true;
				}
			}
			First = 0;
		}
		
		// Sid's throw

		if (First == 0)
		{
			for (int darts = 0; darts < 3; darts++)
			{
				//If statement to break out of for loop if the score is at 0
				if (Sid.get_score() == 0)
				{
					return false;
				}

				if (Sid.get_score() > 61)
				{
					Sid.minus_score(Throw.throw_treble(20, Sid.get_SuccessRate())); // This line throws a dart at a treble 20 and will then minus the score
				}
				else if (Sid.get_score() <= 61 && Sid.get_score() > 41)
				{
					Sid.minus_score(Throw.throw_double(20));
				}
				else if (Sid.get_score() == 50)
				{
					Sid.minus_score(Throw.throw_bull(Sid.get_SuccessRate())); // This line throws a dart at the bull and will then minus the score
				}

				else if (Sid.get_score() <= 41)
				{
					for (int i = 0; i < 20; i++)
					{
						if (Sid.get_score() == Even_Numbers[i])
						{
							int x = Sid.get_score() / 2;
							Sid.minus_score(Throw.throw_double(x));
						}
						
						if (Sid.get_score() == 41)
						{
							Sid.minus_score(Throw.throw_single(1));
						}
					}

					for (int i = 0; i < 9; i++)
					{
						if (Sid.get_score() == Odd_Numbers[i])
						{
							// Strategy to get close to 2 so player can throw for a double 1 for the win
							int aim = Sid.get_score() - 2;
							aim = rand() % aim;
							Sid.minus_score(Throw.throw_single(aim));
						}
					}

					for (int i = 9; i < 19; i++)
					{
						if (Sid.get_score() == Odd_Numbers[i])
						{
							// Strategy to throw for a random odd number so a double can be thrown for a win
							int b = rand() % 9;
							Sid.minus_score(Throw.throw_single(Odd_Numbers[b]));
						}
					}
				}

				if (Sid.get_score() == 1 || Sid.get_score() < 0)
				{
					// Resets score if the player gets a 1 or below
					Sid.set_score(score_SidReset);
					darts = 3;
				}

				if (Sid.get_score() == 0)
				{
					return false;
				}
			}
			First = 1;
		}
	}
}

bool Game::play_set()
{
	Joe_GameWins = 0;
	Sid_GameWins = 0;
	bool win;

	// When one of the players gets to 3 games won the while loop will break
	// A value will be returned which will decide who won the set

	while (Joe_GameWins != 3 && Sid_GameWins != 3)
	{	
		win = play_game();
		//cout << win << endl;
		if (win == 1)
		{
			Joe_GameWins = Joe_GameWins + 1;
		}

		if (win == 0)
		{
			Sid_GameWins = Sid_GameWins + 1;
		}
	}
	
	if (Joe_GameWins == 3)
	{
		Joe_GameWins = 0;
		Sid_GameWins = 0;
		return true;
	}
	if (Sid_GameWins == 3)
	{
		Joe_GameWins = 0;
		Sid_GameWins = 0;
		return false;
	}
}

void Game::play_match()
{
	Joe_SetWins = 0;
	Sid_SetWins = 0;
	bool win;

	while (Joe_SetWins != 7 && Sid_SetWins != 7)
	{
		win = play_set();
		//cout << win << endl;

		if (win == 1)
		{
			Joe_SetWins = Joe_SetWins + 1;
		}

		if (win == 0)
		{
			Sid_SetWins = Sid_SetWins + 1;
		}
	}

	// If statements to add to the total match wins array 
	if (Joe_SetWins == 7 && Sid_SetWins == 0)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[0] = MatchWins[0] + 1;
	}

	if (Joe_SetWins == 7 && Sid_SetWins == 1)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[1] = MatchWins[1] + 1;
	}

	if (Joe_SetWins == 7 && Sid_SetWins == 2)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[2] = MatchWins[2] + 1;
	}

	if (Joe_SetWins == 7 && Sid_SetWins == 3)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[3] = MatchWins[3] + 1;
	}
	
	if (Joe_SetWins == 7 && Sid_SetWins == 4)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[4] = MatchWins[4] + 1;
	}
	
	if (Joe_SetWins == 7 && Sid_SetWins == 5)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[5] = MatchWins[5] + 1;
	}
	
	if (Joe_SetWins == 7 && Sid_SetWins == 6)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[6] = MatchWins[6] + 1;
	}
	
	if (Joe_SetWins == 0 && Sid_SetWins == 7)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[7] = MatchWins[7] + 1;
	}
	
	if (Joe_SetWins == 1 && Sid_SetWins == 7)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[8] = MatchWins[8] + 1;
	}
	
	if (Joe_SetWins == 2 && Sid_SetWins == 7)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[9] = MatchWins[9] + 1;
	}
	
	if (Joe_SetWins == 3 && Sid_SetWins == 7)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[10] = MatchWins[10] + 1;
	}
	
	if (Joe_SetWins == 4 && Sid_SetWins == 7)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[11] = MatchWins[11] + 1;
	}
	
	if (Joe_SetWins == 5 && Sid_SetWins == 7)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[12] = MatchWins[12] + 1;
	}
	
	if (Joe_SetWins == 6 && Sid_SetWins == 7)
	{
		Joe_SetWins = 0;
		Sid_SetWins = 0;
		MatchWins[13] = MatchWins[13] + 1;
	}
	

}

void Game::output()
{
	int no_of_matches = 100;
	
	for (int i = 0; i < no_of_matches; i++)
	{
		play_match();
	}

	// The final output which will be displayed to the user

	cout << "Joe - Sid" << "	      Frequency" << "		Matches Simulated - " << no_of_matches << endl;
	cout << " 7  -  0" << "		" << (MatchWins[0] / no_of_matches) * 100 << "%" << endl;
	cout << " 7  -  1" << "		" << (MatchWins[1] / no_of_matches) * 100 << "%" << endl;
	cout << " 7  -  2" << "		" << (MatchWins[2] / no_of_matches) * 100 << "%" << endl;
	cout << " 7  -  3" << "		" << (MatchWins[3] / no_of_matches) * 100 << "%" << endl;
	cout << " 7  -  4" << "		" << (MatchWins[4] / no_of_matches) * 100 << "%" << endl;
	cout << " 7  -  5" << "		" << (MatchWins[5] / no_of_matches) * 100 << "%" << endl;
	cout << " 7  -  6" << "		" << (MatchWins[6] / no_of_matches) * 100 << "%" << endl;
	cout << " 0  -  7" << "		" << (MatchWins[7] / no_of_matches) * 100 << "%" << endl;
	cout << " 1  -  7" << "		" << (MatchWins[8] / no_of_matches) * 100 << "%" << endl;
	cout << " 2  -  7" << "		" << (MatchWins[9] / no_of_matches) * 100 << "%" << endl;
	cout << " 3  -  7" << "		" << (MatchWins[10] / no_of_matches) * 100 << "%" << endl;
	cout << " 4  -  7" << "		" << (MatchWins[11] / no_of_matches) * 100 << "%" << endl;
	cout << " 5  -  7" << "		" << (MatchWins[12] / no_of_matches) * 100 << "%" << endl;
	cout << " 6  -  7" << "		" << (MatchWins[13] / no_of_matches) * 100 << "%" << endl;
	
}