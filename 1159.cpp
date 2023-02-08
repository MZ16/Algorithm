#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,chk=0;
	int A[26] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		A[(int)s[0] - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		if (A[i] >= 5) { printf("%c", i + 97); chk = 1; }
	}
	if (!chk)cout << "PREDAJA";
	return 0;
}