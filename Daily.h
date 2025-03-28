#pragma once

#include "Common.h"

class DailyProblems
{
	std::vector<std::vector<int>> directions = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
public:
	int leastBricks(std::vector<std::vector<int>>& wall);

	int snakesAndLadders(std::vector<std::vector<int>>& board);
	string CustomSortString(string order, string s);
	std::vector<int> sortedSquares(std::vector<int>& nums);
	int minOperations(std::vector<std::vector<int>>& grid, int x);
	int minimumIndex(std::vector<int>& nums);
	std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries);
	int minMutation(string startGene, string endGene, std::vector<string>& bank);
};