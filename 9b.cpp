#include <bits/stdc++.h>

using namespace std;

#define NUM 393911906

int main()
{
	string line;
	vector<uint32_t> nums;

	// Get the numbers

	while (getline(cin, line))
	{
		nums.push_back(atoi(line.c_str()));
	}

	// Do the checking

	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = i; j < nums.size(); j++)
		{
			// Count the sum between these indices

			size_t sum = 0;

			for (size_t k = i; k < j + 1; k++)
			{
				sum += nums[k];
			}

			if (sum == NUM)
			{
				size_t smallest = 49124948203304, largest = 0;

				for (size_t k = i; k < j + 1; k++)
				{
					if (nums[k] > largest) largest = nums[k];
					if (nums[k] < smallest) smallest = nums[k];
				}

				printf("Found answer from indices [ %ld, %ld ]. Answer = %ld\n",
					i, j, smallest + largest);
			}
		}
	}
}