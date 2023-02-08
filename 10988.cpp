#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int chk = 1;
	cin >> s;
	string s2 = s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] != s[i]) {
			chk = 0;
			break;
		}
	}
	cout << chk;

	return 0;
}