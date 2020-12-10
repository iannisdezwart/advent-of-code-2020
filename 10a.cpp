#include <bits/stdc++.h>

using namespace std;

int main()
{
	string line;
	unordered_set<uint8_t> adapters;

	// Insert everything to the set

	while (getline(cin, line))
	{
		adapters.insert(atoi(line.c_str()));
	}

	// Start the chain

	uint8_t chain_length = 0;
	uint8_t current_joltage = 0;
	uint8_t differences_of_1 = 0;
	uint8_t differences_of_3 = 0;

	printf("Starting joltage = 0\n");

	while (chain_length < adapters.size())
	{
		if (adapters.count(current_joltage + 1))
		{
			// Prefer an increment of 1

			current_joltage++;
			differences_of_1++;
		}
		else if (adapters.count(current_joltage + 2))
		{
			// If that's not available, choose an increment of 2

			current_joltage += 2;
		}
		else
		{
			// Finally, take the increment of 3

			current_joltage += 3;
			differences_of_3++;
		}

		printf("New joltage = %hhu, chain length = %hhu\n",
			current_joltage, chain_length);

		chain_length++;
	}

	// Add the last difference of 3

	differences_of_3++;

	printf("Answer = %d\n", differences_of_1 * differences_of_3);
}