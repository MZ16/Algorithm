#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int N, M, arr[54][54];
vector<vector<int>> chikenList;
vector<pii> home, chiken;
int ans = 987654321;


void combi(int start, vector<int> v) {
	if (v.size() == M) {
		chikenList.push_back(v);
		return;
	}
	for (int i = start+1; i < chiken.size(); i++) {
		v.push_back(i);
		combi(i,v);
		v.pop_back();
	}
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)home.push_back({ i,j });
			if (arr[i][j] == 2)chiken.push_back({i,j});
		}
	}
	vector<int> v;
	combi(-1, v);

	for (vector<int> cList : chikenList) { // M���� ġŲ�� ����
		int ret = 0;
		for (pii _home : home) { // ��(����) �� ġŲ��(�ټ�)
			int _min = 987654321;
			for (int val : cList) { // M���� ������ �ϳ��� �ε���( (ex)idx=0,{0,1,2} )
				int dist = abs(_home.first - chiken[val].first) + abs(_home.second - chiken[val].second); // |r1-r2| + |c1-c2|
				_min = min(dist, _min);
			}
			ret += _min; // �ϳ��� ���� �ε����� �ּҰ�
		}
		ans = min(ans, ret); // ��ü ������ �ּҰ�
	}
	cout << ans;

	return 0;
}