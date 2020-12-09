#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	set<char> qs;
	int tc = 0;
	bool j = false;

	while (getline(cin, s)) {
		if (s == "") {
			int c = 0;
			for (char i = 'a'; i <= 'z'; i++) {
				if (qs.count(i)) c++;
			}
			qs.clear();
			printf("total = %d\n", c);
			tc += c;
			j = false;
		} else {
			if (!j) {
				printf("first line: %s\n", s.c_str());
				for (int i = 0; i < s.size(); i++) {
					qs.insert(s[i]);
				}
				j = true;
			} else {
				set<char> sqs;
				printf("second line: %s\n", s.c_str());
				for (int i = 0; i < s.size(); i++) {
					sqs.insert(s[i]);
				}
				for (char i = 'a'; i <= 'z'; i++) {
					if (!sqs.count(i)) {
						qs.erase(i);
					}
				}
			}
		}
	}

	printf("\n======\ngrand total = %d\n", tc);
}