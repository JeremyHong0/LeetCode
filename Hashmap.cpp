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
