#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	vector<uint16_t> ids;

	while (getline(cin, s)) {
		uint16_t r = 0;
		uint8_t c = 0, j = 64;

		for (int i = 0; i < 7; i++) {
			if (s[i] == 'B') r += j;
			j >>= 1;
		}

		j = 4;

		for (int i = 7; i < 10; i++) {
			if (s[i] == 'R') c += j;
			j >>= 1;
		}

		uint16_t id = r * 8 + c;
		ids.push_back(id);
	}

	sort(ids.begin(), ids.end());

	uint16_t last_id = ids[0];

	for (int i = 1; i < ids.size(); i++) {
		if (ids[i] != last_id + 1) cout << ids[i] - 1 << '\n';
		last_id = ids[i];
	}
}