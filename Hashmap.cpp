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
std::unordered_map<char, int> balloon;
void resetBalloon()
{
    balloon['b'] = 1; balloon['a'] = 1; balloon['l'] = 2;
    balloon['o'] = 2; balloon['n'] = 1;
}
int Hashmap::maxNumberOfBalloons(string text)
{
    int count = 0;
    resetBalloon();

    for (char c : text)
    {
        if (balloon.find(c) != balloon.end() && --balloon[c] == 0)
        {
            balloon.erase(c);
        }

        if (balloon.empty())
        {
            ++count;
            resetBalloon();
        }
    }

    return count;
}

std::vector<std::vector<string>> Hashmap::groupAnagrams(std::vector<string>& strs)
{
    std::unordered_map<string, std::vector<string>> groups;

    for(string s : strs)
    {
        string temp = s;
        std::sort(s.begin(), s.end());
        groups[s].push_back(temp);
    }
    std::vector<std::vector<string>> ans;
    for(auto [key, val]: groups)
    {
        ans.push_back(val);
    }
    return ans;
}

std::vector<string> Hashmap::findAllRecipes(std::vector<string>& recipes, std::vector<std::vector<string>>& ingredients, std::vector<string>& supplies)
{
    std::unordered_set<string> available(supplies.begin(), supplies.end());
    std::queue<int> recipeQueue;
    int n = recipes.size();
    for (int i = 0; i < n; ++i)
    {
        recipeQueue.push(i);
    }

    std::vector<string> created;
    int lastSize = -1;
    while (static_cast<int>(available.size()) > lastSize)
    {
        lastSize = available.size();

        int recipeSize = recipeQueue.size();
        while (recipeSize-- > 0)
        {
            int recipeIdx = recipeQueue.front(); recipeQueue.pop();
            bool bCanCreate = true;
            for (string& ingredient : ingredients[recipeIdx])
            {
                if (available.find(ingredient) == available.end())
                {
                    bCanCreate = false;
                    break;
                }
            }

            if (!bCanCreate)
            {
                recipeQueue.push(recipeIdx);
            }
            else
            {
                available.insert(recipes[recipeIdx]);
                created.push_back(recipes[recipeIdx]);
            }
        }
    }

    return created;
}

