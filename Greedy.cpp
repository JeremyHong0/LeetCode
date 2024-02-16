#include "Greedy.h"


Greedy::Greedy()
{
}

bool Greedy::asteroidsDestroyed(int mass, std::vector<int>& asteroids)
{
	std::sort(asteroids.begin(), asteroids.end());

	for(int asteroid : asteroids)
	{
		if (asteroid <= mass)
			mass += asteroid;
		else
			return false;
	}

	return true;
}

// set x as element of index 0.
// if [current - x] > k -> which means we need new subsequence, ++answer.
int Greedy::partitionArray(std::vector<int>& nums, int k)
{
	std::sort(nums.begin(), nums.end());
	int x = nums[0];
	int answer = 1;
	if (nums.size() <= 1)
		return answer;

	for(size_t i = 1; i < nums.size(); ++i)
	{
		if(nums[i] - x > k)
		{
			x = nums[i];
			answer++;
		}
	}

	return answer;
}

// keep update the sum until sum is greater then current elem.
long long Greedy::largestPerimeter(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	long long sum = 0;
	long long answer = -1;
	for(int i = 0; i < nums.size(); ++i)
	{
		if(i > 2 && sum > nums[i])
		{
			answer = sum + nums[i];
		}
		sum += nums[i];
	}

	return answer;
}

int Greedy::findLeastNumOfUniqueInts(std::vector<int>& arr, int k)
{
	// make sorted map of arr
	std::map<int, int> freq;
	for(int i : arr)
	{
		freq[i]++;
	}
	std::vector<int> arrFreq;
	for(auto [key, val] : freq)
	{
		arrFreq.push_back(val);
	}
	std::sort(arrFreq.begin(), arrFreq.end());

	const int n = arrFreq.size();
	for(int i = 0; i < n; ++i)
	{
		k -= arrFreq[i];
		if(k < 0)
		{
			return n - i;
		}
	}

	return 0;
}

