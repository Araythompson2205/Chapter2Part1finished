// Participants: Christopher, Duyen Tran, Long Duong
// Date: 02-28-21
// Description: Class that generates random number

#pragma once
#include <vector>

using namespace std;

class RandomGenerator
{
public:
	RandomGenerator() = default;
	// Preconditions: NA
	// Postconditions: Initialize class instance
	RandomGenerator(long _seed, long _multiplier, long _increment, long _modulus);
	
	// Preconditions: Instance was properly initialized
	// Postconditions: The new internal seed is set 
	void setSeed(long newSeed);

	// Preconditions: Instance was properly initialized
	// Postconditions: Return new random int from 0 to modulus
	long getRandomInt();

	// Preconditions: Instance was properly initialized
	// Postconditions: Return a new random float in [0, 1)
	double getRandomInUnitInterval();

	// Precondition : Instance was properly initialized
	// Postcondition: outputs the cycle length of current parameters
	long long getCycleLength();

	// Precondition: Instance was properly initialized
	// Postcondition: outputs boolean whether cycleLength is greater than threshold
	bool isCycleLengthGreaterThan(long threshold);

private:
	long multiplier, increment, modulus;
	long long seed;
};
