#pragma once
#include "Common.h"

class Arrays
{
public:
	int waysToSplitArray(std::vector<int>& nums);

	void moveZeroes(std::vector<int>& nums);
	std::vector<int> applyOperations(std::vector<int>& nums);
	int lengthOfLongestSubstring(string s);
	std::vector<int> pivotArray(std::vector<int>& nums, int pivot);
	std::vector<int> getAverages(std::vector<int>& nums, int k);
};