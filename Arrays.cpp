#include "Arrays.h"

int Arrays::waysToSplitArray(std::vector<int>& nums)
{
    int n = nums.size(), count = 0;
    std::vector<int> prefixSum = { nums[0] };

    for (int i = 1; i < n; ++i)
    {
        prefixSum.push_back(prefixSum.back() + nums[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if (prefixSum[i] >= prefixSum[n - 1] - prefixSum[i])
            ++count;
    }

    return count;
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

std::vector<int> Arrays::pivotArray(std::vector<int>& nums, int pivot)
{
	std::vector<int> left;
	std::deque<int> right;

    for(int n : nums)
    {
		if (n < pivot)
			left.push_back(n);
		else if (n == pivot)
			right.push_front(n);
        else
			right.push_back(n);
    }

	std::vector<int> res;
	for (int n : left)
	{
		res.push_back(n);
	}

	for (int n : right)
	{
		res.push_back(n);
	}

    return res;
}

std::vector<int> Arrays::getAverages(std::vector<int>& nums, int k)
{
    int n = nums.size();
    std::vector<int64_t> prefixSum(n);
    prefixSum[0] = nums[0];

    for (int i = 1; i < n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    std::vector<int> res(n);
    for (int i = 0; i < n; ++i)
{
        // invalid left side
        if (i < k)
        {
            res[i] = -1;
        }
        // valid part
        else if (k + i < n)
        {
            res[i] = (prefixSum[k + i] - prefixSum[i - k] + nums[i - k]) / (2 * k + 1);
        }
        // invalid right side
        else if (k + i >= n)
        {
            res[i] = -1;
        }
    }

    return res;
}

int Arrays::numSubarrayProductLessThanK(std::vector<int>& nums, int k)
{
    int sum = 0;
    int left = 0, curr = 1;

    for(int i = 0; i < nums.size(); ++i)
    {
        curr *= nums[i];

        while(curr >= k)
        {
            curr /= nums[left];
            ++left;
        }

        sum += (i - left + 1);
    }

    return sum;
}

string Arrays::reverseOnlyLetters(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        // swap
        if (std::isalpha(s[left]) && std::isalpha(s[right]))
        {
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            ++left; --right;
        }
        else if (!std::isalpha(s[left]))
        {
            ++left;
        }
        else if (!std::isalpha(s[right]))
        {
            --right;
        }
    }

    return s;
}

int Arrays::findMiddleIndex(std::vector<int>& nums)
{
	int n = nums.size();
	int rightSum = 0;

	for (int i = n - 1; i >= 0; --i)
	{
		rightSum += nums[i];
	}

    int leftSum = 0;
    for(int i = 0; i < n; ++i)
    {
		rightSum -= nums[i];

        if (leftSum == rightSum)
            return i;

		leftSum += nums[i];
    }

    return -1;
}

int Arrays::numberOfSubstrings(string s)
{
    int left = 0, count = 0;
    std::unordered_map<char, int> freq;

    for(int i = 0; i < s.size(); ++i)
    {
        freq[s[i]]++;

        while(freq.size() >= 3)
        {
            count += s.size() - i;

            if (--freq[s[left]] == 0)
                freq.erase(s[left]);
            ++left;
        }
    }

    return count;
}

long long Arrays::maximumSubarraySum(std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> freq;
    long long maxSum = 0, currSum = 0;
    for (int i = 0; i < k; ++i)
    {
        freq[nums[i]]++;
        currSum += nums[i];
    }
    if (freq.size() == k)
        maxSum = std::max(maxSum, currSum);

    for (int i = k; i < nums.size(); ++i)
    {
        currSum += nums[i] - nums[i - k];
        freq[nums[i]]++;
        if (--freq[nums[i - k]] == 0)
            freq.erase(nums[i - k]);

        if (freq.size() == k)
            maxSum = std::max(maxSum, currSum);
    }

    return maxSum;
}

std::vector<int> Arrays::decrypt(std::vector<int>& code, int k)
{
    int n = code.size();
    std::vector<int> answer(n, 0);

    if (k == 0)
        return answer;
    bool bFlag;
    if (k < 0)
        bFlag = false;
    else
        bFlag = true;

    int loop = abs(k);
    for (int i = 0; i < n; ++i)
    {
        int j;
        if(bFlag)
        {
            j = i + 1;
        }
        else
        {
            j = i - 1;
        }
        int sum = 0;
        int k = 0;
        while (k < loop)
        {
            if(bFlag)
            {
                if (j >= n)
                {
                    j = 0;
                }
                sum += code[j];
                ++j; ++k;
            }
            else
            {
                if(j < 0)
                {
                    j = n - 1;
                }
                sum += code[j];
                --j; ++k;
            }
        }

        answer[i] = sum;
    }

    return answer;
}

int Arrays::maximumLengthSubstring(string s)
{
    std::unordered_map<char, int> freq;
    int left = 0;
    int maxLen = INT_MIN;
    for (int i = 0; i < s.size(); ++i)
    {
        char currChar = s[i];
        ++freq[currChar];
        while (freq[currChar] > 2)
        {
            if (--freq[s[left]] == 0)
                freq.erase(s[left]);
            ++left;
        }
        maxLen = std::max(maxLen, (i - left + 1));
    }

    return maxLen;
}

int Arrays::countDays(int days, std::vector<std::vector<int>>& meetings)
{
    int count = 0, n = meetings.size(), latestEnd = 0;
	std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& a, const std::vector<int>& b)
		{
			return a[0] < b[0];
		});
    for(int i = 0; i < n; ++i)
    {
        int start = meetings[i][0], end = meetings[i][1];
        if(start > latestEnd + 1)
        {
            count += start - latestEnd - 1;
        }

        latestEnd = std::max(latestEnd, end);
    }

    count += days - latestEnd;

    return count;
}
