#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	uint16_t h_id = 0;

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
		if (id > h_id) h_id = id;
	}

	cout << h_id;
}