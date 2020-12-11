#include <bits/stdc++.h>

using namespace std;

#define WIDTH 91
#define HEIGHT 90

enum states { FLOOR, EMPTY, OCCUPIED };
enum states seats[HEIGHT][WIDTH];
enum states new_seats[HEIGHT][WIDTH];

int find_adjacent(int y, int x, int dy, int dx)
{
	x += dx;
	y += dy;

	while (x >= 0 && x <= WIDTH - 1 && y >= 0 && y <= HEIGHT - 1)
	{
		switch (seats[y][x])
		{
			case EMPTY:
				return 0;

			case OCCUPIED:
				return 1;
		}

		x += dx;
		y += dy;
	}

	return 0;
}

int count_adjacent_deep(int y, int x)
{
	int count = 0;

	// Left

	count += find_adjacent(y, x, -1, -1);
	count += find_adjacent(y, x, 0, -1);
	count += find_adjacent(y, x, 1, -1);

	// Right

	count += find_adjacent(y, x, -1, 1);
	count += find_adjacent(y, x, 0, 1);
	count += find_adjacent(y, x, 1, 1);

	// Top

	count += find_adjacent(y, x, -1, 0);

	// Bottom

	count += find_adjacent(y, x, 1, 0);

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

			// printf("c_a_d = %d\n", count_adjacent_deep(y, x));

			switch (seats[y][x])
			{
				case FLOOR:
					break;

				case EMPTY:
					if (count_adjacent_deep(y, x) == 0)
					{
						new_seats[y][x] = OCCUPIED;
						changed = true;
					}

					break;

				case OCCUPIED:
					if (count_adjacent_deep(y, x) >= 5)
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