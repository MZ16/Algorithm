#include <bits/stdc++.h>
using namespace std;

const int MAX = 52;
vector<int> home, chicken;
vector<vector<int>> chicken_list;
int _map[MAX][MAX];
int N, M;

void dfs(int idx, vector<int>& v) {
	if (v.size() == M) {
		chicken_list.push_back(v);
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		v.push_back(i);
		dfs(i + 1, v);
		v.pop_back();
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 1)home.push_back(i * 1000 + j);
			if (_map[i][j] == 2)chicken.push_back(i * 1000 + j);
		}
	}

	vector<int> tmp;
	dfs(0, tmp);

	int ans = 987654321;
	for (vector<int> cList : chicken_list) {
		int ret = 0;
		for (int h : home) {
			int MIN = 987654321;
			for (int idx : cList) {
				int val = abs(h / 1000 - chicken[idx] / 1000) + abs(h % 1000 - chicken[idx] % 1000);
				MIN = min(val, MIN);
			}
			ret += MIN;
		}
		ans = min(ans, ret);
	}
	cout << ans;

	return 0;
}

/*
1. 모든 치킨집좌표와 집의 좌표를 저장한다.
2. 주어진 M만큼 치킨집의 경우의 수를 모두 조합한다.
3. 위의 두가지를 활용하여 최소값의 치킨거리를 구한다
	1. 치킨리스트는 이중벡터임을 명심하고 사용할 것
	2. 하나의 집과 조합된 치킨거리 모두를 비교하여 최소값을 찾는다.
	3. 다른 조합의 치킨거리값과 최소를 비교한다

치킨 거리 연산 시 절댓값을 사용해야 함을 잊으면 안된다.
*/