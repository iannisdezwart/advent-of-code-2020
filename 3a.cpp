#include <bits/stdc++.h>

using namespace std;

vector<string> forest;

bool is_tree(size_t x, size_t y)
{
	return forest[y][x % forest[y].size()] == '#';
}

uint64_t traverse(size_t slope_x, size_t slope_y)
{
	size_t x = slope_x, y = slope_y;
	uint64_t trees = 0;

	while (y < forest.size()) {
		if (is_tree(x, y)) trees++;

		x += slope_x;
		y += slope_y;
	}

	return trees;
}

int main()
{
	string current;

	while (getline(cin, current)) {
		forest.push_back(current);
	}

	uint64_t trees = traverse(1, 1) * traverse(3, 1)
		* traverse(5, 1) * traverse(7, 1) * traverse(1, 2);

	printf("ans = %ld", trees);
}