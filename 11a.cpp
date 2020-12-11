#include <bits/stdc++.h>

using namespace std;

#define WIDTH 91
#define HEIGHT 90

enum states { FLOOR, EMPTY, OCCUPIED };
enum states seats[HEIGHT][WIDTH];
enum states new_seats[HEIGHT][WIDTH];

int count_adjacent(int y, int x)
{
	// If a seat is occupied (#) and four or more seats adjacent
	// to it are also occupied, the seat becomes empty.

	int count = 0;

	// Left side

	if (x != 0)
	{
		if (y != 0 && seats[y - 1][x - 1] == OCCUPIED) count++;
		if (seats[y][x - 1] == OCCUPIED) count++;
		if (y != HEIGHT - 1 && seats[y + 1][x - 1] == OCCUPIED) count++;
	}

	// Right side

	if (x != WIDTH - 1)
	{
		if (y != 0 && seats[y - 1][x + 1] == OCCUPIED) count++;
		if (seats[y][x + 1] == OCCUPIED) count++;
		if (y != HEIGHT - 1 && seats[y + 1][x + 1] == OCCUPIED) count++;
	}

	// Top

	if (y != 0 && seats[y - 1][x] == OCCUPIED) count++;

	// Bottom

	if (y != HEIGHT - 1 && seats[y + 1][x] == OCCUPIED) count++;

	return count;
}

int tick()
{
	int changed_seats = 0;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			bool changed = false;

			switch (seats[y][x])
			{
				case FLOOR:
					break;

				case EMPTY:
					if (count_adjacent(y, x) == 0)
					{
						new_seats[y][x] = OCCUPIED;
						changed = true;
					}

					break;

				case OCCUPIED:
					if (count_adjacent(y, x) >= 4)
					{
						new_seats[y][x] = EMPTY;
						changed = true;
					}

					break;
			}

			changed_seats += changed;
		}
	}

	// Update the seats

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			seats[y][x] = new_seats[y][x];
		}
	}

	printf("Ran a tick. %d seats changed\n", changed_seats);

	return changed_seats;
}

int main()
{
	string line;
	int y = 0;

	// Get input from stdin

	while (getline(cin, line))
	{
		for (int x = 0; x < WIDTH; x++)
		{
			enum states state;

			if (line[x] == '.') state = FLOOR;
			else state = EMPTY;

			seats[y][x] = state;
		}

		y++;
	}

	// Tick until no seats change

	while (tick());

	// Count number of occupied seats

	int occupied_seats = 0;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (seats[y][x] == OCCUPIED) occupied_seats++;
		}
	}

	printf("Answer = %d\n", occupied_seats);
}