// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

#include <thread>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base Constructor" << endl;
	}
	~Base()
	{
		cout << "Base Destructor" << endl;
	}
	virtual void show() { cout << "Base" << endl; }

	int pub_A;
protected:
	int prt_A;

	void print();
private:

	int prv_A;
};

class Child : public Base
{
public:
	Child()
	{
		cout << "Child Constructor" << endl;
	}
	Child(int a)
	{
		cout << "Child Constructor(int)" << endl;
	}
	~Child()
	{
		cout << "Child Destructor" << endl;
	}
	void show() override { cout << "Child" << endl; }
	
};

ListNode* reverseList(ListNode* head) {
	ListNode* curr = head;
	ListNode* prev = nullptr;
	while(curr != nullptr)
	{
		ListNode* nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
 	}

	return prev;
}

ListNode* swapPairs(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	ListNode* dummy = head->next;
	while (curr != nullptr)
	{
		ListNode* nextNode = curr->next->next;
		curr->next->next = curr;
		prev = curr;
		curr = nextNode;
		prev->next = nextNode->next;
	}

	return dummy;
}
int g_count = 0;
void thread_function()
{
	for (int i = 0; i < 1000; i++)
		g_count = g_count + 1;
}


int main()
{
	/*C c;
	c.show();
	std::thread t1(thread_function);
	std::thread t2(thread_function);

	t1.join();
	t2.join();
	
	printf("count = %d\n", g_count);


	Child* ptr = new Child();
	Base* bptr = ptr;
	ptr->show();
	bptr->show();
	delete ptr;

	ListNode* sixth = new ListNode(6);
	ListNode* fifth = new ListNode(5, sixth);
	ListNode* forth = new ListNode(4, fifth);
	ListNode* third = new ListNode(3, forth);
	ListNode* second = new ListNode(2, third);
	ListNode* first = new ListNode(1, second);

	ListNode* head = first;*/



	DailyProblems dp;

	Arrays array;
	std::vector<int> vec = { 5, 7, 1, 4 };
	std::vector<std::vector<int>> vec2 = {
		{-1,-1,-1,-1,-1,-1} ,
		{-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,35,-1,-1,13,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,15,-1,-1,-1,-1}
	};
	dp.snakesAndLadders(vec2);
	array.countDays(10, vec2);
	array.maximumLengthSubstring("bcbbbcba");
	array.decrypt(vec, 3);
	array.reverseOnlyLetters("a-bC-dEf-ghIj");
	array.getAverages(vec, 3);
	array.applyOperations(vec);
	array.waysToSplitArray(vec);

	string s = "pwwkew";
	array.lengthOfLongestSubstring(s);

	dp.sortedSquares(vec);

	Hashmap Hashmap;
	std::vector<string> recipes = { "bread" };
	vector<vector<string>> ingredients = { {"yeast", "flour"}};
	vector<string> supplies = { "yeast" };
	Hashmap.findAllRecipes(recipes, ingredients, supplies);
	Hashmap.maxNumberOfBalloons("loonbalxballpoon");

	Hashmap.numberOfSubarrays(vec, 2);

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
