#pragma once

#include "Common.h"

using namespace std;
class Graphs
{
	std::vector<std::vector<bool>> bSeen2DVector_;
	std::vector<bool> bSeen1DVector_;
	std::unordered_set<int> SeenSet_;

	// down, right, up, left
	std::vector<std::vector<int>> directions_ = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	std::vector<std::vector<char>> grid_;
	int m_ = 0, n_ = 0;

	std::unordered_map<int, std::vector<int>> graph;
	std::vector<std::vector<int>> adjList;
	std::set<std::vector<int>> roads;

	bool isValid(int row, int col);
	bool checkExit(int row, int col);

	void dfs(int row, int col);
	int dfs(int node);
	void dfsBase(int node);
	void dfsSet(int node);
public:

	int findCircleNum(std::vector<std::vector<int>>& isConnected);
	int numIslands(std::vector<std::vector<char>>& grid);
	int minReorder(int n, std::vector<std::vector<int>>& connections);
	bool canVisitAllRooms(std::vector<std::vector<int>>& rooms);

	int ShortestPath(std::vector<std::vector<int>>& grid, int k);
	int nearestExit(vector<vector<char>>& maze, vector<int> entrance);
	int orangesRotting(vector<vector<int>>& grid);
};