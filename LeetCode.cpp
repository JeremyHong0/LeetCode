// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

int main()
{
	DailyProblems dp;

	Hashmap Hashmap;

	std::vector<std::vector<int>> trust = { {1, 2, 2, 1},
		{3, 1, 2},{1, 3, 2},{2, 4},{3, 1, 2},{1, 3, 1, 1} };
	dp.leastBricks(trust);

	//Hashmap.findJudge(3, trust);

	//cout << "Hello CMake." << endl;
	Greedy Greedy;

	int mass = 10;
	std::vector<int> vector = { 1,12,1,2,5,50,3 };
	Greedy.largestPerimeter(vector);

	return 0;
}
