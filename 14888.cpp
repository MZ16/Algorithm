#include <bits/stdc++.h>
using namespace std;

int N;
int arr[11];
int visited[11];
int oper[4];
vector<int> _index; // oper_idx
vector<char> v; // operater 저장

int MAX = -1000000000;
int MIN = 1000000000;

void dfs() {
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
		dfs();
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
	dfs();
	cout << MAX << "\n" << MIN;
	return 0;
}

// 공유된 코드에 비해 시간이 오래걸리는 이유
// 해당코드는 백트레킹하여 연산자 인덱스의 순열을 구하여 저장된 연산자 벡터와 매칭하여 풀었는 문제이다.
// N의 범위가 11이하 이므로 순열의 공식인 nPr에 대입하면 최댓값이 약 4천만까지 나올 수 있어 실행시간이 꽤 걸릴 수 있다.
// STL next_permutation 의 시간복잡도는 O(N)이다. 이게 훨씬 효율적일듯.

 
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