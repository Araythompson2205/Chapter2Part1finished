// Participant: Duyen Tran
// Date: 02-27-21
// Description: Generate random that follows Gaussian distribution

#pragma once
#include "RandomGenerator.h"

class GaussianRandom
{
public:
	// Precondition: NA
	// Postcondition: Initialize private members
	GaussianRandom(long seed, long multiplier, long increment, long modulus, double _median, double _sd);

	// Precondition: Instance was properly initialized
	// Postcondition: Output next random number in Gaussian distribution
	double getNextInGaussianDistribution();

private:
	double median, sd;
	RandomGenerator randomGenerator;
};
