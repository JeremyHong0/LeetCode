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
	int numSubarrayProductLessThanK(std::vector<int>& nums, int k);
	string reverseOnlyLetters(string s);
	int findMiddleIndex(std::vector<int>& nums);
	int numberOfSubstrings(string s);
	long long maximumSubarraySum(std::vector<int>& nums, int k);
	std::vector<int> decrypt(std::vector<int>& code, int k);
	int maximumLengthSubstring(string s);
	int countDays(int days, std::vector<std::vector<int>>& meetings);

};