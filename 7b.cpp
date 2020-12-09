#include <bits/stdc++.h>

using namespace std;

struct InnerBag {
	string name;
	size_t size;
};

unordered_map<string, vector<struct InnerBag>> bags;
size_t n = 0;

// unordered_set<string> visited;
void dfs(string name, size_t weight)
{
	// if (visited.count(name)) return;
	// printf("possible, inserting %s\n", current_name.c_str());
	vector<struct InnerBag> inner_bags = bags[name];
	n += weight;

	// visited.insert(name);

	for (size_t i = 0; i < inner_bags.size(); i++) {
		dfs(inner_bags[i].name, inner_bags[i].size * weight);
	}

	// visited.erase(name);
}

void traverse()
{
	dfs("shiny gold", 1);
	printf("ans = %ld, total = %ld\n", n - 1, bags.size());
}

int main()
{
	string s;

	while (getline(cin, s)) {
		size_t name_end_index = s.find(" bags contain ");
		string name = s.substr(0, name_end_index);
		vector<struct InnerBag> inner_bags;
		// printf("line: %s\n", s.c_str());
		printf("bag: name = %s\n", name.c_str());

		if (s.find(" no other bags.") == string::npos) {
			size_t offset = name_end_index + 14;

			while (offset < s.size() - 2) {
				size_t comma_index = s.find(',', offset);
				size_t bag_index = s.find(" bag", offset);

				if (comma_index == string::npos) {
					comma_index = s.size() - 1;
				}

				size_t inner_size = atoi(s.substr(offset, 1).c_str());
				string inner_name = s.substr(offset + 2, bag_index - offset - 2);

				// printf("\tinner_bag: name = %s, size = %ld\n", inner_name.c_str(), inner_size);
				inner_bags.push_back({ inner_name, inner_size });

				offset = comma_index + 2;
			}
		}

		bags.insert(make_pair(name, inner_bags));
	}

	traverse();
}