#include "Throw.h"
int Throw::throw_single(int d)
{
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},{0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;

	// 1 to 20 single
	if (r < 80)
	{
		return d; // return score
	
	}

	else if (r < 90)
	{
		return bd[0][d]; // return score to the left
		
	}
	else if (r < 100)
	{
		return bd[1][d];
		
	}

}
int Throw::throw_treble(int d, int p)
{
	//  return result of throwing for treble d with accuracy p%  (p<90)
	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	int r = rand() % 100 + 1;

	if (r < p)
	{
		return 3 * d;
	}
	else if (r < 90)
	{
		return d;
	}
	else if (r < 93)
	{
		return 3 * bd[0][d];
	}
	else if (r < 96)
	{
		return 3 * bd[1][d];
	}
	else if (r < 98)
	{
		return bd[0][d];
	}
	else
	{
		return bd[1][d];
	}
}

int Throw::throw_double(int d)
{
	//  return result of throwing for double d with accuracy 80%
	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	int r = rand() % 100 + 1;

	if (r < 80)
	{
		return 2 * d;
	}
	else if (r < 85)
	{
		return 0;
	}
	else if (r < 90)
	{
		return d;
	}
	else if (r < 93)
	{
		return 2 * bd[0][d];
	}
	else if (r < 96)
	{
		return 2 * bd[1][d];
	}
	else if (r < 98)
	{
		return bd[0][d];
	}
	else
	{
		return bd[1][d];
	}
}

int Throw::throw_bull(int s)
{
	int r = rand() % 100 + 1;

	if (r < s)
	{
		return 50;
	}

	else
	{
		r = rand() % 20;
		return r;
		
	}

}
