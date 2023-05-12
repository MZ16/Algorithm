#include <bits/stdc++.h>
using namespace std;

// XOR = 0,0 = 0 / 0,1 = 1 / 1,0 = 1 / 1,1 = 0
// strtol
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		string s,tmp;
		int N, M;
		int flag = 1;
		cin >> N >> M;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '1')tmp.push_back('0');
			else tmp.push_back('1');
		}
		for (int j = 0; j < N - 1; j++) {
			string s2;
			cin >> s2;
			if (s2 != s && s2 != tmp)flag = 0;
		}
		if(flag) cout << "#" << i << " " << "yes" << "\n";
		else cout << "#" << i << " " << "no" << "\n";
		
		
	}
	return 0;
}