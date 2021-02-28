#pragma once

class IncrementalDistribution
{
public:
	// Person: Gia
	//Precondition: n/a
	//Postcondition:Initialized internal array to 0
	IncrementalDistribution();
	
	// Person: Gia 
	//Precondition: need to pass in value from RandomGeneraot getRandomInUnitInterval()
	//Postcondition: count the uniformly distributed number in range [0 to 1)
	void add(double newElement);

	// Person: Gia
	//Precondition: n/a
	//Postcondition:Outputs the internal array, so that the first array element
	//representing the range from [0.0 to 0.1) and so on ..  
	const long* getDistribution();

private:
	long frequencies[10];
};
