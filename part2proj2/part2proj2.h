// Participant: Long Duong
// Date: 02-27-21
// Description: Implementation of various UI functions.

#pragma once

#include <iostream>
#include <random>
#include "RandomGenerator.h"
#include "IncrementalDistribution.h"
#include "GaussianRandom.h"
#include "ui/MixedColumn.h"
#include "ui/Table.h"
#include "ui/config.h"

using namespace std;

// Preconditions: Expects seed, multiplier, increment and modulus
// Postconditions: Outputs these parameters to user
void diplayParameters(long seed, long multiplier, long increment, long modulus);

// Preconditions: Expects array of frequency
// Postconditions: Outputs the frequency in table with graph
void displayDistribution(const long frequency[10]);

// Preconditions: NA
// Postconditions: Test the maximum length of random number cycle
void test1();

// Preconditions: NA
// Postconditions: Test the uniform distribution generator
void testUniform();

// Preconditions: NA
// Postconditions: Test the Gaussian distribution generator
void testGaussian();

// Preconditions: NA
// Postconditions: Run all 3 tests: cycle length, uniform distribution test, and gaussian distribution test
void part2();

// Preconditions: NA
// Postconditions: Execute program #2 with various initialization.
int part2Main();