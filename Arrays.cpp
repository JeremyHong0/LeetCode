#include "Arrays.h"

int Arrays::waysToSplitArray(std::vector<int>& nums)
{
    return 0;
}

void Arrays::moveZeroes(std::vector<int>& nums)
{
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found.
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
    // After we have finished processing new elements,
    // all the non-zero elements are already at beginning of array.
    // We just need to fill remaining elements in the array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

std::vector<int> Arrays::applyOperations(std::vector<int>& nums)
{
    int nonZeroIdx = 0;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
			if (nums[i] != 0)
				nonZeroIdx = i;
        }
        if (nums[i + 1] != 0)
        {
            nonZeroIdx = i + 1;
        }
    }

    nonZeroIdx = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] != 0)
			nums[nonZeroIdx++] = nums[i];
    }

    for (int i = nonZeroIdx; i < nums.size(); ++i)
    {
        nums[i] = 0;
    }
    //for(int i = 0;)
    return nums;
}

int Arrays::lengthOfLongestSubstring(string s)
{
	std::unordered_set<char> set;
    int left = 0;
    int maxLen = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        while (set.find(s[i]) != set.end())
        {
            set.erase(s[left]);
            ++left;
        }
        set.insert(s[i]);

        maxLen = std::max(maxLen, (i - left + 1));
    }

    return maxLen;
}
