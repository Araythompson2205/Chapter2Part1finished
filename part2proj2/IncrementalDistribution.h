// Participant: Gia Minh, Long Duong
// Date: 02-27-21
// Description: Class that calculates distribution incrementally.

#pragma once

class IncrementalDistribution
{
public:
	//Precondition: n/a
	//Postcondition:Initialized internal array to 0
	IncrementalDistribution();
	
	//Precondition: need to pass in value from RandomGeneraot getRandomInUnitInterval()
	//Postcondition: count the uniformly distributed number in range [0 to 1)
	void add(double newElement);

	//Precondition: n/a
	//Postcondition:Outputs the internal array, so that the first array element
	const long* getDistribution();

private:
	long frequencies[10];
};
