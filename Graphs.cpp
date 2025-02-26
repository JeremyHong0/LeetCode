#include "Graphs.h"

#if 1
void Graphs::dfs(int row, int col)
{
	int count = 0;
	for(std::vector<int>& dir : directions_)
	{
		int nextRow = row + dir[0], nextCol = col + dir[1];
		if(isValid(nextRow, nextCol) && !bSeen2DVector_[nextRow][nextCol])
		{
			bSeen2DVector_[nextRow][nextCol] = true;
			dfs(nextRow, nextCol);
		}
	}
}


int Graphs::dfs(int node)
{
	int answer = 0;
	for (int neighbor : graph[node])
	{
		if (!bSeen1DVector_[neighbor])
		{
			if (roads.contains({ node, neighbor }))
			{
				++answer;
			}
			bSeen1DVector_[neighbor] = true;
			answer += dfs(neighbor);
		}
	}

	return answer;
}

void Graphs::dfsBase(int node)
{
	for(int neighbor : graph[node])
	{
		if(!bSeen1DVector_[neighbor])
		{
			bSeen1DVector_[neighbor] = true;
			dfsBase(neighbor);
		}
	}
}

void Graphs::dfsSet(int node)
{
	for(int neighbor : adjList[node])
	{
		if(!SeenSet_.contains(neighbor))
		{
			SeenSet_.insert(neighbor);
			dfs(neighbor);
		}
	}
}

#else

void Graphs::dfs(int row, int col)
{
	std::stack<std::pair<int, int>> stack;
	stack.push(std::pair(row, col));

	while(!stack.empty())
	{
		auto [row, col] = stack.top(); stack.pop();

		for(std::vector<int>& dir : directions_)
		{
			int nextRow = row + dir[0], nextCol = col + dir[1];
			if(isValid(nextRow, nextCol) && !bSeen2DVector_[nextRow][nextCol])
			{
				bSeen2DVector_[nextRow][nextCol] = true;
				stack.push(std::pair(nextRow, nextCol));
			}
		}
	}
}

int Graphs::dfs(int node)
{
	int answer = 0;
	std::stack<int> stack;
	stack.push(node);

	while(!stack.empty())
	{
		int n = stack.top(); stack.pop();

		for(int neighbor : graph[n])
		{
			if (!bSeen1DVector_[neighbor])
			{
				if (roads.contains({ n, neighbor }))
				{
					++answer;
				}
				bSeen1DVector_[neighbor] = true;
				stack.push(neighbor);
			}
		}
	}

	return answer;
}

void Graphs::dfsSet(int node)
{
	std::stack<int> stack;
	stack.push(node);

	while(!stack.empty())
	{
		int top = stack.top(); stack.pop();

		for(int neighbor : adjList[top])
		{
			if(!SeenSet_.contains(neighbor))
			{
				SeenSet_.insert(neighbor);
				stack.push(neighbor);
			}
		}
	}
}


#endif
vector<int> entrance_;

bool Graphs::isValid(int row, int col)
{
	return (row >= 0 && col >= 0 && row < m_ && col < n_);
}

bool Graphs::checkExit(int row, int col)
{
	if (row == entrance_[0] && col == entrance_[1])
		return false;

	return row == 0 || row == m_ || col == 0 || col == n_;
}

int Graphs::findCircleNum(std::vector<std::vector<int>>& isConnected)
{
	int n = isConnected.size();
	bSeen1DVector_ = std::vector<bool>(n);
	int count = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			if(isConnected[i][j] == 1)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(!bSeen1DVector_[i])
		{
			++count;
			bSeen1DVector_[i] = true;
			dfsBase(i);
		}
	}

	return count;
}

int Graphs::numIslands(std::vector<std::vector<char>>& grid)
{
	int count = 0;
	m_ = grid.size(), n_ = grid[0].size();
	grid_ = grid;
	bSeen2DVector_ = std::vector(m_, std::vector<bool>(n_, false));
	for(int i = 0; i < m_; ++i)
	{
		for(int j = 0; j < n_; ++j)
		{
			if(grid[i][j] == '1' && !bSeen2DVector_[i][j])
			{
				bSeen2DVector_[i][j] = true;
				++count;
				dfs(i, j);
			}
		}
	}

	return count;
}

int Graphs::minReorder(int n, std::vector<std::vector<int>>& connections)
{
	bSeen1DVector_ = std::vector<bool>(n, false);

	for(std::vector<int>& edges : connections)
	{
		int x = edges[0], y = edges[1];
		graph[x].push_back(y);
		graph[y].push_back(x);
		roads.insert({ x, y });
	}
	bSeen1DVector_[0] = true;

	return dfs(0);
}

bool Graphs::canVisitAllRooms(std::vector<std::vector<int>>& rooms)
{
	int n = rooms.size();
	adjList = rooms;
	SeenSet_.insert(0);

	dfsSet(0);

	return SeenSet_.size() == rooms.size();
}

int Graphs::ShortestPath(std::vector<std::vector<int>>& grid, int k)
{
	m_ = grid.size(), n_ = grid[0].size();
	// {row, col, step, remaining k}
	std::queue<std::vector<int>> queue;
	std::vector<std::vector<bool>> seen(m_, std::vector<bool>(n_));

	queue.push({ 0, 0, 0, k });

	while (!queue.empty())
	{
		std::vector<int> curr = queue.front(); queue.pop();
		int currRow = curr[0], currCol = curr[1], currStep = curr[2], currK = curr[3];

		if (currRow == (m_ - 1) && currCol == (n_ - 1))
			return currStep;

		for (std::vector<int>& dir : directions_)
		{
			int nextRow = currRow + dir[0], nextCol = currCol + dir[1];
			if (isValid(nextRow, nextCol))
			{
				if (grid[nextRow][nextCol] == 0)
				{
					if (!seen[nextRow][nextCol])
					{
						seen[nextRow][nextCol] = true;
						queue.push({ nextRow, nextCol, currStep + 1, currK });
					}
				}
				else if (currK > 0 && grid[nextRow][nextCol] == 1)
				{
					if (!seen[nextRow][nextCol])
					{
						seen[nextRow][nextCol] = true;
						queue.push({ nextRow, nextCol, currStep + 1, currK - 1 });
					}
				}
			}
		}
	}

	return -1;
}

int Graphs::nearestExit(vector<vector<char>>& maze, vector<int> entrance)
{
	m_ = maze.size(), n_ = maze[0].size();
	entrance_ = entrance;

	// {row, col, step}
	queue<vector<int>> queue;
	queue.push({ entrance[0], entrance[1], 0 });
	vector<vector<bool>> seen(m_, vector<bool>(n_, false));
	seen[entrance[0]][entrance[1]] = true;

	while (!queue.empty())
	{
		vector<int> curr = queue.front(); queue.pop();
		int row = curr[0], col = curr[1], step = curr[2];

		// if we reach exit, return current step
		if (checkExit(row, col))
		{
			return step;
		}

		for (vector<int>& dir : directions_)
		{
			int nextRow = row + dir[0], nextCol = col + dir[1];
			if (isValid(nextRow, nextCol) && !seen[nextRow][nextCol] && maze[nextRow][nextCol] != '+')
			{
				seen[nextRow][nextCol] = true;
				queue.push({ nextRow, nextCol, step + 1 });
			}
		}
	}

	return -1;
}

int Graphs::orangesRotting(vector<vector<int>>& grid)
{
	m_ = grid.size(), n_ = grid[0].size();

	queue<vector<int>> queue;
	vector<vector<int>> seen(m_, vector<int>(n_));
	int freshCount = 0;
	for (int i = 0; i < m_; ++i)
	{
		for (int j = 0; j < n_; ++j)
		{
			if (grid[i][j] == 2)
			{
				queue.push({ i, j, 0 });
			}
			else if (grid[i][j] == 1)
			{
				++freshCount;
			}
		}
	}
	int rottenCount = 0;
	if (rottenCount == freshCount)
	{
		return 0;
	}
	while (!queue.empty())
	{
		vector<int> curr = queue.front(); queue.pop();
		int row = curr[0], col = curr[1], step = curr[2];

		if (rottenCount == freshCount)
		{
			return step;
		}

		for (vector<int>& dir : directions_)
		{
			int nextRow = row + dir[0], nextCol = col + dir[1];
			if (isValid(nextRow, nextCol) && grid[nextRow][nextCol] == 1 && !seen[nextRow][nextCol])
			{
				seen[nextRow][nextCol] = true;
				queue.push({ nextRow, nextCol, step + 1 });
				++rottenCount;
				cout << step << "," << rottenCount << endl;
			}
		}
	}

	return -1;
}

