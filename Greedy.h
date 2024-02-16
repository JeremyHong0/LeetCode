#pragma once

#include "Common.h"

class Greedy
{
public:
	Greedy();

	bool asteroidsDestroyed(int mass, std::vector<int>& asteroids);
	int partitionArray(std::vector<int>& nums, int k);

	long long largestPerimeter(std::vector<int>& nums);
	int findLeastNumOfUniqueInts(std::vector<int>& arr, int k);
};

