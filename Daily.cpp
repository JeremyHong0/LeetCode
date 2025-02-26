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
