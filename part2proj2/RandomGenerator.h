// Participants: Christopher
// Date: 02-28-21
// Description: Chapter 2 - Random Generator

//Participants: Duyen TRan
//Date:02/26/2021
//Description: 2 last function.

#pragma once
#include <vector>

using namespace std;

class RandomGenerator
{
public:
	RandomGenerator() = default;
	// Person: Christopher
	// init class
	RandomGenerator(long _seed, long _multiplier, long _increment, long _modulus);
	
	// Person: Chrisopher
	// assign new seed
	void setSeed(long newSeed);

	// Person: Christopher
	// Get a new random Int from 0 to modulus (refer to problem 11 in textbook)
	long getRandomInt();

	// Person: DUYEN
	// Get a random double from [0, 1). (refer to 12 in textbook pg 94)
	double getRandomInUnitInterval();

private:
	long multiplier, increment, modulus;
	long long seed;
};
