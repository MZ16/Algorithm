#include <bits/stdc++.h>
using namespace std;

int visited[11];
char inq[11];
int N;
string sMin="9999999999", sMax="0", s;

bool cmp(string a, string b) {
	if (a.size() > b.size())return 1;
	else if (a > b) return 1;
	else return 0;
}

void dfs(int prev,int idx) {

	if (s.size() == N+1) {
		if (cmp(s, sMax)) sMax = s;
		if(!cmp(s, sMin)) sMin = s;
		return;
	}
	if (inq[idx-1] == '>') {
		for (int i = 0; i < prev; i++) {			
			if (visited[i])continue;
			visited[i] = 1;
			s += to_string(i);
			dfs(i, idx+1);
			s.pop_back();
			visited[i] = 0;
		}
	}

	if (inq[idx - 1] == '<') {
		for (int i = prev+1; i < 10; i++) {
			if (visited[i])continue;
			visited[i] = 1;
			s += to_string(i);
			dfs(i, idx + 1);
			s.pop_back();
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inq[i];
	}
	
	for (int i = 0; i <= 9; i++) {
		visited[i] = 1;
		s += to_string(i);
		dfs(i, 1);
		s.pop_back();
		visited[i] = 0;
	}
	
	cout << sMax << "\n";
	cout << sMin;
	return 0;
}
// ?