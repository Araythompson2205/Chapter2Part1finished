// Participants: Christopher, Duyen Tran, Long Duong
// Date: 02-28-21
// Description: Class that generates random number


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

long long RandomGenerator::getCycleLength()
{
	long seedBackup = seed;
	long firstRandom = getRandomInt();
	long long cycleLength = 0;
	do
		cycleLength++;
	while (getRandomInt() != firstRandom);
	seed = seedBackup;
	return cycleLength;
}

bool RandomGenerator::isCycleLengthGreaterThan(long threshold)
{
	long seedBackup = seed;
	long firstRandom = getRandomInt();
	long long cycleLength = 0;
	do
	{
		cycleLength++;
		if (cycleLength > threshold) return true;
	}
	while (getRandomInt() != firstRandom);
	seed = seedBackup;
	return false;
}
