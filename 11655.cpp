#include <bits/stdc++.h>
using namespace std;
//공백 포함 입력은 getline(cin,배열);
int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 65 && s[i] <= 90)) {
			/*s[i] += 13;
			if (s[i] > 90) s[i] -= 26;*/
			if (s[i] + 13 > 90) s[i] -= 13;
			else s[i] += 13;
		}
		if ((s[i] >= 97 && s[i] <= 122)) {
			/*s[i] += 13;
			if (s[i] > 122) s[i] -= 26;*/
			if (s[i] + 13 > 122) s[i] -= 13;
			else s[i] += 13;
		}
	}
	cout << s;

	return 0;
}