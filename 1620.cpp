#include <bits/stdc++.h>
using namespace std;

string s;
map<string, int> mp1;
map<int, string> mp2;

int main() {
	// ios_base 사용 안하면 시간초과나는 기괴한 문제..
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;
	

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		
		cin >> s;
		mp1[s] = i + 1;
		mp2[i + 1] = s;
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (atoi(s.c_str())) cout << mp2[atoi(s.c_str())]<<"\n";
		else cout << mp1[s]<<"\n";
		/*if (!atoi(s.c_str()))cout << mp1[s] << "\n";
		else cout << mp2[atoi(s.c_str())];*/
	}

	return 0;
}