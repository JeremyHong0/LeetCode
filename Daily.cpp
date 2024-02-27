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
