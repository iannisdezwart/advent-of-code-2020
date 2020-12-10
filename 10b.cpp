/*
	So this actually took me a while, as I hadn't really practiced any
	dynamic programming problems for quite some time.

	I think I should thank Antti Laaksonen here for creating the wonderful
	Competitive Programmer's Handbook. Chapter 7 (Dynamic Programming) helped
	me a lot here ;-).

	If you're stuck, or don't know a lot about dynamic programming yet,
	I would recommend taking a look at Laaksonen's book here:
	https://cses.fi/book/book.pdf

	Good luck solving the - in my opinion - hardest AoC 2020 problem yet!
*/

#include <bits/stdc++.h>

using namespace std;

// Number of lines in the input plus 1

#define NUM_OF_ADAPTERS 109

set<uint8_t> adapters;
uint8_t adapters_arr[NUM_OF_ADAPTERS];
uint8_t max_joltage = 0;

int main()
{
	string line;

	// Insert everything to the set, takes O(n * log n)

	while (getline(cin, line))
	{
		uint8_t joltage = atoi(line.c_str());

		// Keep track of the maximum joltage

		if (joltage > max_joltage)
		{
			max_joltage = joltage;
		}

		adapters.insert(joltage);
	}

	// Insert the first adapter

	adapters.insert(0);

	// Insert the final adapter

	max_joltage += 3;
	adapters.insert(max_joltage);

	// Create the sorted adapter array, takes O(n * log n)

	uint8_t i = 0;

	for (uint8_t joltage : adapters)
	{
		adapters_arr[i++] = joltage;
	}

	// Create the DP array and zero initialise

	uint64_t *dp_array = new uint64_t[max_joltage + 1];
	memset(dp_array, 0, max_joltage + 1);

	// DP solving algorithm takes O(n)

	dp_array[0] = 1;

	for (uint8_t i = 0; i < NUM_OF_ADAPTERS; i++)
	{
		uint8_t joltage = adapters_arr[i];

		for (uint8_t j = 1; j <= 3; j++) {
			uint8_t lower_joltage = joltage - j;

			if (joltage >= j && adapters.count(lower_joltage))
			{
				dp_array[joltage] += dp_array[lower_joltage];
			}
		}
	}

	printf("Answer = %ld\n", dp_array[max_joltage - 3]);

	// Free heap allocated memory

	delete dp_array;
}