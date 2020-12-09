#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c = 0;
	string l;

	while (getline(cin, l)) {
		int sl = 0;
		int el = 0;

		for (int i = 0; i < l.size(); i++) {
			if (l[i] >= '0' && l[i] <= '9') sl++;
			else break;
		}

		for (int i = sl + 1; i <  l.size(); i++) {
			if (l[i] >= '0' && l[i] <= '9') el++;
			else break;
		}

		int s = atoi(l.substr(0, sl).c_str());
		int e = atoi(l.substr(sl + 1, el).c_str());

		char m = l[sl + 1 + el + 1];
		int mc = 0;
		string p = l.substr(sl + 1 + el + 4);

		printf("sl = %d, el = %d, s = %d, e = %d, m = %c, p = %s\n", sl, el, s, e, m, p.c_str());

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == m) mc++;
		}

		if (mc >= s && mc <= e) c++;
	}

	cout << c;
}