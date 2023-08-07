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
1. ��� ġŲ����ǥ�� ���� ��ǥ�� �����Ѵ�.
2. �־��� M��ŭ ġŲ���� ����� ���� ��� �����Ѵ�.
3. ���� �ΰ����� Ȱ���Ͽ� �ּҰ��� ġŲ�Ÿ��� ���Ѵ�
	1. ġŲ����Ʈ�� ���ߺ������� ����ϰ� ����� ��
	2. �ϳ��� ���� ���յ� ġŲ�Ÿ� ��θ� ���Ͽ� �ּҰ��� ã�´�.
	3. �ٸ� ������ ġŲ�Ÿ����� �ּҸ� ���Ѵ�

ġŲ �Ÿ� ���� �� ������ ����ؾ� ���� ������ �ȵȴ�.
*/