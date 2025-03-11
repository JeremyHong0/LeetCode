#include "Hashmap.h"

int Hashmap::findJudge(int n, std::vector<std::vector<int>>& trust)
{
    std::vector<int> votePlaced(n + 1);
    std::vector<int> voteGot(n + 1);

    for(const auto& label : trust)
    {
        votePlaced[label[0]]++;
        voteGot[label[1]]++;
    }

    for(int i = 1; i < (n + 1); ++i)
    {
	    if(votePlaced[i] == 0 && voteGot[i] == (n - 1))
	    {
            return i;
	    }
    }

    return -1;
}

int Hashmap::numberOfSubarrays(std::vector<int>& nums, int k)
{
    int currOddNums = 0, answer = 0;
	std::unordered_map<int, int> oddNums;
    oddNums[0] = 1;

    for(int i : nums)
    {
	    if(i % 2 == 1)
	    {
			currOddNums++;
	    }
        answer += oddNums[currOddNums - k];
        oddNums[currOddNums]++;
    }

    return answer;
}
