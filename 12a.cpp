#include <bits/stdc++.h>

using namespace std;

int angle = 180;
double x = 0;
double y = 0;

int main()
{
	string line;

	printf("x = %f, y = %f, angle = %d\n", x, y, angle);

	while (getline(cin, line))
	{
		char action = line[0];
		int argument = atoi(line.substr(1).c_str());

		printf("Performing %c(%d)\n", action, argument);

		switch (action)
		{
			case 'N':
				y -= argument;
				break;

			case 'S':
				y += argument;
				break;

			case 'E':
				x -= argument;
				break;

			case 'W':
				x += argument;
				break;

			case 'L':
				angle -= argument;
				angle %= 360;
				if (angle < 0) angle += 360;
				break;

			case 'R':
				angle += argument;
				angle %= 360;
				break;

			case 'F':
				x += cos(M_PI * angle / 180) * argument;
				y -= sin(M_PI * angle / 180) * argument;
				break;
		}

		printf("x = %f, y = %f, angle = %d\n", x, y, angle);
	}

	printf("Manhattan distance = %f\n", abs(x) + abs(y));
}