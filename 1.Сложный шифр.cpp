#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

char getPopularChar(string s) {
	int a[26] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		int index = c - 'a';
		a[index]++;
	}

	int imax = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] > a[imax]) {
			imax = i;
		}
	}

	return (char)(imax + 'a');
}

string solve(string s) {
	string s1, s2, s3;
	char popular;

	if (s.length() == 1) return s;

	s1 = solve(s.substr(0, s.length() / 2));
	s2 = solve(s.substr(s.length() / 2, s.length()));
	s3 = s1 + s2;

	popular = getPopularChar(s3);
	//cout << s1 << ' ' << popular << ' ' << s2 << '\n';
	return s1 + popular + s2;
}

int main() {
	string s;
	cin >> s;

	cout << solve(s) << endl;
	return 0;
}