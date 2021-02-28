// Participants: Christopher
// Date: 02-28-21
// Description: Chapter 2 - Random Generator

//Participants: Duyen TRan
//Date:02/26/2021
//Description: 2 last function.


#include <time.h>
#include "RandomGenerator.h"

#include<iostream>
#include<cstdlib>

using namespace std;

RandomGenerator::RandomGenerator(long _seed, long _multiplier, long _increment, long _modulus)
{
	seed = _seed;
	multiplier = _multiplier;
	increment = _increment;
	modulus = _modulus;
}

void RandomGenerator::setSeed(long newSeed)
{
	seed = newSeed;
}

long RandomGenerator::getRandomInt()
{
	seed = (multiplier * seed + increment) % modulus;
	return seed;
}

double RandomGenerator::getRandomInUnitInterval()
{
	return getRandomInt() / static_cast<double>(modulus);

}

