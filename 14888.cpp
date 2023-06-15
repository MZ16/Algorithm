#include <bits/stdc++.h>
using namespace std;

int N;
int arr[104];
int visited[104];
int oper[4];
vector<int> _index; // oper_idx
vector<char> v; // operater ÀúÀå

int MAX = -1300000000;
int MIN = 1300000000;

void dfs(int idx) {
	if (_index.size() == N - 1) {
		int result = arr[0];
		for (int i = 0; i < N-1; i++) {
			if (v[_index[i]] == '+')result += arr[i+1];
			else if (v[_index[i]] == '-')result -= arr[i+1];
			else if (v[_index[i]] == '*')result *= arr[i+1];
			else if (v[_index[i]] == '/')result /= arr[i+1];
		}
		MAX = max(MAX, result);
		MIN = min(MIN, result);
		return;
	}

	for (int i = 0; i < N-1; i++) { // operate
		if (visited[i])continue;
		visited[i] = 1;
		_index.push_back(i);
		dfs(idx + 1);
		visited[i] = 0;
		_index.pop_back();
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) { 
		cin >> oper[i]; 
		if(oper[i])
			for (int j = 0; j < oper[i]; j++) {
				if (i == 0)v.push_back('+');
				else if (i == 1)v.push_back('-');
				else if (i == 2)v.push_back('*');
				else if (i == 3)v.push_back('/');				
			}
	}
	dfs(0);
	cout << MAX << "\n" << MIN;
	return 0;
}

/*
2 <= N <= 11, 1 <= A <= 100,
+, -, *, /

Input_ex
2
1 2
1 0 0 0
=
5
1 2 3 4 5
1 1 1 1
=
5
100 100 100 100 10
0 0 4 0
=
11
1 2 3 4 5 6 7 8 9 10 11
10 0 0 0
=
6
1 2 3 4 5 6
5 0 0 0
=
2
-9 3
0 0 0 1
*/