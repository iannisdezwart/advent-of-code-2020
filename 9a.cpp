#include <bits/stdc++.h>

using namespace std;

int main()
{
	string line;
	vector<uint32_t> nums;
	unordered_set<uint32_t> last_25_nums;

	// Get the numbers

	while (getline(cin, line))
	{
		nums.push_back(atoi(line.c_str()));
	}

	// Put the first 25 numbers in the last_25_nums set

	for (size_t i = 0; i < 25; i++)
	{
		last_25_nums.insert(nums[i]);
	}

	// Do the checking

	for (size_t i = 25; i < nums.size(); i++)
	{
		uint32_t num = nums[i];
		bool ok = false;

		// Check if this number is valid

		for (auto it = last_25_nums.begin(); it != last_25_nums.end(); it++)
		{
			uint32_t co_num = *it;
			if (num > co_num && last_25_nums.count(num - co_num))
			{
				ok = true;
				break;
			}
		}

		if (!ok)
		{
			printf("Number %ld is not ok\n", num);
		}

		// Update the last_25_nums set

		last_25_nums.erase(nums[i - 25]);
		last_25_nums.insert(num);
	}
}