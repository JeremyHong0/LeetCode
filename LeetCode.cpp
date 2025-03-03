// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

int main()
{
	DailyProblems dp;

	Arrays array;
	std::vector<int> vec = { 1,2,2,1,1,0 };
	array.applyOperations(vec);

	string s = "pwwkew";
	array.lengthOfLongestSubstring(s);

	dp.sortedSquares(vec);

	Hashmap Hashmap;

	std::vector<std::vector<int>> trust = { {1, 2, 2, 1},
		{3, 1, 2},{1, 3, 2},{2, 4},{3, 1, 2},{1, 3, 1, 1} };

	std::vector<std::vector<int>> grid = { {2,1,1} ,{1,1,1},{0,1,2}};
	dp.leastBricks(trust);
	Graphs Graphs;
	std::vector<std::vector<int>> connections = { {0,1} ,{1,3},{2,3},{4,0},{4,5} };
	std::vector<std::vector<int>> isConnected = { {1,1,0} ,{1,1,0},{0,0,1} };
	Graphs.orangesRotting(grid);
	//Graphs.ShortestPath(grid, 1);
	//Graphs.numIslands(grid);
	Graphs.findCircleNum(isConnected);
	Graphs.minReorder(6, connections);
	//Hashmap.findJudge(3, trust);

	//cout << "Hello CMake." << endl;
	Greedy Greedy;

	int mass = 10;
	std::vector<int> vector = { 1,12,1,2,5,50,3 };
	Greedy.largestPerimeter(vector);

	return 0;
}
