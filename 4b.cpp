#include <bits/stdc++.h>

using namespace std;

string get(string s, string f)
{
	size_t start = s.find(f) + 4;
	size_t end = s.find(' ', start);
	return s.substr(start, end - start);
}

bool ok(string s)
{
	if (s.find("byr:") == string::npos) return false;
	int byr = atoi(get(s, "byr:").c_str());
	printf("byr = %d\n", byr);
	if (byr < 1920 || byr > 2020) return false;

	if (s.find("iyr:") == string::npos) return false;
	int iyr = atoi(get(s, "iyr:").c_str());
	printf("iyr = %d\n", iyr);
	if (iyr < 2010 || iyr > 2020) return false;

	if (s.find("eyr:") == string::npos) return false;
	int eyr = atoi(get(s, "eyr:").c_str());
	printf("eyr = %d\n", eyr);
	if (eyr < 2020 || eyr > 2030) return false;

	if (s.find("hgt:") == string::npos) return false;
	string hgt = get(s, "hgt:");
	printf("hgt = %s\n", hgt.c_str());
	int hgt_v = atoi(hgt.substr(0, hgt.size() - 2).c_str());
	printf("hgt_v = %d\n", hgt_v);
	if (hgt[hgt.size() - 2] == 'c' && hgt[hgt.size() - 1] == 'm') {
		// cm
		if (hgt_v < 150 || hgt_v > 193) return false;
	} else {
		// in
		if (hgt_v < 59 || hgt_v > 76) return false;
	}

	if (s.find("hcl:") == string::npos) return false;
	string hcl = get(s, "hcl:");
	printf("hcl = %s\n", hcl.c_str());
	if (hcl.size() != 7) return false;
	if (hcl[0] != '#') return false;
	for (int i = 1; i < 7; i++) {
		if (hcl[i] < '0') return false;
		if (hcl[i] > '9' && hcl[i] < 'a') return false;
		if (hcl[i] > 'f') return false;
	}

	if (s.find("ecl:") == string::npos) return false;
	string ecl = get(s, "ecl:");
	printf("ecl = %s\n", ecl.c_str());
	if (!(ecl == "amb" || ecl == "blu" || ecl == "brn" || ecl == "gry"
		|| ecl == "grn" || ecl == "hzl" || ecl == "oth")) return false;

	if (s.find("pid:") == string::npos) return false;
	string pid = get(s, "pid:");
	printf("pid = %s\n", pid.c_str());
	if (pid.size() != 9) return false;
	for (int i = 0; i < 9; i++) {
		if (pid[i] < '0' || pid[i] > '9') return false;
	}

	return true;
}

int main()
{
	string g, s = "";
	bool running = false;
	size_t c = 0;

	while (getline(cin, g)) {
		if (!running) {
			s += " " + g;
			printf("appended\n%s\n", g.c_str());
			running = true;
		} else {
			if (g == "") {
				running = false;
				printf("str:\n%s\n", s.c_str());
				if (ok(s)) c++;
				printf("ok = %d\n\n", ok(s));
				s = "";
			} else {
				s += " " + g;
				printf("appended\n%s\n", g.c_str());
			}
		}
	}

	if (ok(s)) c++;
	printf("ok = %d\n\n", ok(s));

	cout << c;
}
