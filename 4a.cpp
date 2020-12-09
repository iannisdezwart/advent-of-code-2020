#include <bits/stdc++.h>

using namespace std;

bool ok(string s)
{
	if (s.find("byr:") == string::npos) return false;
	if (s.find("iyr:") == string::npos) return false;
	if (s.find("eyr:") == string::npos) return false;
	if (s.find("hgt:") == string::npos) return false;
	if (s.find("hcl:") == string::npos) return false;
	if (s.find("ecl:") == string::npos) return false;
	if (s.find("pid:") == string::npos) return false;
	return true;
}

int main()
{
	string g, s = "";
	bool running = false;
	size_t c = 0;

	while (getline(cin, g)) {
		if (!running) {
			s += g;
			printf("appended\n%s\n", g.c_str());
			running = true;
		} else {
			if (g == "") {
				running = false;
				printf("str:\n%s\n", s.c_str());
				if (ok(s)) c++;
				printf("ok = %d\n", ok(s));
				s = "";
			} else {
				s += g;
				printf("appended\n%s\n", g.c_str());
			}
		}
	}

	if (ok(s)) c++;
	printf("ok = %d", ok(s));

	cout << c;
}
