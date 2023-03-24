#include <bits/stdc++.h>
using namespace std;

// 괄호문제는 대체로 stack이다.

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		vector<char>v;
		int flag = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(')v.push_back(s[j]);
			else if (s[j] == ')' && !v.empty())v.pop_back();
			else flag = 1;
		}
		if (!flag&&v.empty())cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}