#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	set<char> qs;
	int tc = 0;

	while (getline(cin, s)) {
		if (s == "") {
			int c = 0;
			for (char i = 'a'; i <= 'z'; i++) {
				if (qs.count(i)) c++;
			}
			qs.clear();
			printf("total = %d\n", c);
			tc += c;
		} else {
			printf("new line: %s\n", s.c_str());
			for (int i = 0; i < s.size(); i++) {
				qs.insert(s[i]);
			}
		}
	}

	int c = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		if (qs.count(i)) c++;
	}
	printf("total = %d\n", c);
	tc += c;

	printf("\n======\ngrand total = %d\n", tc);
}