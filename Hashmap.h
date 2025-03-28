#pragma once

#include "Common.h"

class Hashmap
{

public:
	int findJudge(int n, std::vector<std::vector<int>>& trust);
	int numberOfSubarrays(std::vector<int>& nums, int k);
	int maxNumberOfBalloons(string text);
	std::vector<std::vector<string>> groupAnagrams(std::vector<string>& strs);
	std::vector<string> findAllRecipes(std::vector<string>& recipes, std::vector<std::vector<string>>& ingredients, std::vector<string>& supplies);
};