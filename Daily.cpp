#include "Daily.h"



int DailyProblems::leastBricks(std::vector<std::vector<int>>& wall)
{
    int n = wall.size();
    std::unordered_map<uint32_t, uint16_t> wallFreq;
    uint16_t maxFreq = 0;

    for (std::vector<int>& row : wall)
    {
        int sum = 0;
        for (size_t i = 0; i < row.size() - 1; ++i)
        {
            sum += row[i];
            wallFreq[sum]++;
            maxFreq = std::max(wallFreq[sum], maxFreq);
        }
    }

    return n - maxFreq;
}

int DailyProblems::snakesAndLadders(std::vector<std::vector<int>>& board)
{
    int n = board.size();
    std::vector<std::pair<int, int>> cells(n * n + 1);
    int label = 1;
    std::vector<int> columns(n);
    std::iota(columns.begin(), columns.end(), 0);
    std::queue<std::pair<int, int>> queue; // <curr cell, move count>
    std::vector<bool> visited(n * n + 1, false);
    queue.push({1, 0});
    visited[1] = true;

    for (int row = n - 1; row >= 0; --row)
    {
        for (int column : columns)
        {
            cells[label++] = { row, column };
        }
        reverse(columns.begin(), columns.end());
    }

    while(!queue.empty())
    {
        auto [currCell, currMove] = queue.front(); queue.pop();
        if (currCell == n * n)
            return currMove;

        for(int i = currCell + 1; i <= std::min(currCell + 6, n * n); ++i)
        {
            auto [row, col] = cells[i];
            int next = board[row][col] == -1 ? i : board[row][col];
            if(!visited[next])
            {
                visited[next] = true;
                queue.push({next, currMove + 1});
            }
        }
    }

    return -1;
}

string DailyProblems::CustomSortString(string order, string s)
{
    std::unordered_map<char, int> freq;
    string result;
    for (char c : s)
    {
        freq[c]++;
    }

    for(char c: order)
    {
	    while(freq[c]-- > 0)
	    {
            result += c;
	    }
    }

    for(auto& [key, val] : freq)
    {
	    while(val-- > 0)
	    {
            result += key;
	    }
    }

    return result;
}

std::vector<int> DailyProblems::sortedSquares(std::vector<int>& nums)
{
    int left = 0, right = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] >= 0)
        {
            right = i;
            left = i - 1;
            break;
        }
    }

    std::vector<int> ans;

    while(left >= 0 && right < nums.size())
    {
        if (abs(nums[left]) > abs(nums[right]))
        {
            ans.push_back(pow(nums[right], 2));
            ++right;
        }
        else
        {
            ans.push_back(pow(nums[left], 2));
            --left;
        }
    }

    while(left >= 0)
    {
        ans.push_back(pow(nums[left], 2));
        --left;
    }

    while(right < nums.size())
    {
        ans.push_back(pow(nums[right], 2));
        ++right;
    }

    return ans;
}

int DailyProblems::minOperations(std::vector<std::vector<int>>& grid, int x)
{
    int n = grid.size(), m = grid[0].size();
    std::vector<int> nums;
    nums.reserve(n * m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int curr = grid[i][j];
            nums.push_back(curr);
        }
    }

    std::sort(nums.begin(), nums.end());
    int mid = nums.size() / 2;
    int count = 0;
    int prev = nums[0];
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && abs(nums[i] - prev) % x > 0)
            return -1;
        count += (abs(nums[mid] - nums[i]) / x);
        prev = nums[i];
    }

    return count;
}

int DailyProblems::minimumIndex(std::vector<int>& nums)
{
	std::unordered_map<int, int> freq;
    int n = nums.size();
    int maxFreq = 0;
    int maxFreqNum = 0;
    for (int num : nums)
    {
        freq[num]++;
        if (freq[num] > maxFreq)
        {
            maxFreq = freq[num];
            maxFreqNum = num;
        }
    }
    int count = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (nums[i] == maxFreqNum)
            ++count;

        if (count * 2 > i + 1 && (maxFreq - count) * 2 > (n - i - 1))
            return i;
    }

    return -1;
}

using MinHeapType = std::priority_queue<
    std::pair<int, std::pair<int, int>>,
    std::vector<std::pair<int, std::pair<int, int>>>,
    std::greater<>
>;

std::vector<int> DailyProblems::maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries)
{
    int n = grid.size(), m = grid[0].size();
    std::vector<int> answer(queries.size());
    std::vector<std::vector<int>> visited(n, std::vector<int>(m, false));
    MinHeapType minHeap;
    minHeap.push({ grid[0][0] , { 0, 0 } });
    visited[0][0] = true;

    std::vector<std::pair<int, int>> sortedQueries;
    for (int i = 0; i < queries.size(); ++i)
    {
        sortedQueries.emplace_back(queries[i], i );
    }
    std::sort(sortedQueries.begin(), sortedQueries.end());

    int count = 0;
    for (const auto& [q, idx] : sortedQueries)
    {
        while (!minHeap.empty() && minHeap.top().first < q)
        {
            auto [currVal, pos] = minHeap.top(); minHeap.pop();
            int currRow = pos.first, currCol = pos.second;
            ++count;
            for (const std::vector<int>& dir : directions)
            {
                int nextRow = currRow + dir[0], nextCol = currCol + dir[1];
                if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < m && !visited[nextRow][nextCol])
                {
                    minHeap.push({ grid[nextRow][nextCol], {nextRow, nextCol} });
                    visited[nextRow][nextCol] = true;
                }
            }
        }
        answer[idx] = count;
    }

    return answer;
}

int DailyProblems::minMutation(string startGene, string endGene, std::vector<string>& bank)
{
	std::queue<std::pair<string, int>> q;
    q.push({ startGene, 0 });
    std::unordered_set<string> seen;
    seen.insert(startGene);
    string gene = "ACGT";

    while (!q.empty())
    {
        auto [currGene, mutationCount] = q.front(); q.pop();
        if (currGene == endGene)
            return mutationCount;

        for (char c : gene)
        {
            for (int i = 0; i < currGene.size(); ++i)
            {
                string nextGene = currGene;
                nextGene[i] = c;
                if (seen.find(nextGene) == seen.end() && find(bank.begin(), bank.end(), nextGene) != bank.end())
                {
                    q.push({ nextGene, mutationCount + 1 });
                    seen.insert(nextGene);
                }
            }
        }
    }

    return -1;
}
