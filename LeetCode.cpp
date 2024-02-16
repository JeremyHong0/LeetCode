// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

int main()
{
	//cout << "Hello CMake." << endl;
	Greedy Greedy;

	int mass = 10;
	std::vector<int> vector = { 1,12,1,2,5,50,3 };
	Greedy.largestPerimeter(vector);

	return 0;
}
