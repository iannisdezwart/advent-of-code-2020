#include <bits/stdc++.h>

using namespace std;

double x = 0;
double y = 0;
double w_x = -10;
double w_y = -1;

double new_w_x;
double new_w_y;

int main()
{
	string line;

	printf("w_x = %f, w_y = %f\n", w_x, w_y);
	printf("x = %f, y = %f\n", x, y);

	while (getline(cin, line))
	{
		char action = line[0];
		int argument = atoi(line.substr(1).c_str());

		printf("Performing %c(%d)\n", action, argument);

		switch (action)
		{
			case 'N':
				w_y -= argument;
				break;

			case 'S':
				w_y += argument;
				break;

			case 'E':
				w_x -= argument;
				break;

			case 'W':
				w_x += argument;
				break;

			case 'L':
				new_w_x = w_x * cos(M_PI * argument / 180) - w_y * sin(M_PI * argument / 180);
				new_w_y = w_x * sin(M_PI * argument / 180) + w_y * cos(M_PI * argument / 180);
				w_x = new_w_x;
				w_y = new_w_y;
				break;

			case 'R':
				new_w_x = w_x * cos(M_PI * -argument / 180) - w_y * sin(M_PI * -argument / 180);
				new_w_y = w_x * sin(M_PI * -argument / 180) + w_y * cos(M_PI * -argument / 180);
				w_x = new_w_x;
				w_y = new_w_y;
				break;

			case 'F':
				x += w_x * argument;
				y += w_y * argument;
				break;
		}

		printf("w_x = %f, w_y = %f\n", w_x, w_y);
		printf("x = %f, y = %f\n", x, y);
	}

	printf("Manhattan distance = %f\n", abs(x) + abs(y));
}