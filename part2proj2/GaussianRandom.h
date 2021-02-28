// Participant: Duyen Tran
// Date: 02-27-21
// Description: Generate random that follows Gaussian distribution

#pragma once
#include "RandomGenerator.h"

class GaussianRandom
{
public:
	GaussianRandom() = default;

	// Precondition: NA
	// Postcondition: Initialize private members
	GaussianRandom(long seed, long multiplier, long increment, long modulus, double _median, double _sd);

	// Precondition: Instance was properly initialized
	// Postcondition: Output next random number in Gaussian distribution
	double getNextInGaussianDistribution();

	// Precondition: Instance was properly initialized
	// Postcondition: Outputs whether cycle length is greater than threshold
	bool isCycleLengthGreaterThan(long threshold);

private:
	double median, sd;
	RandomGenerator randomGenerator;
};
