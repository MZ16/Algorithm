#include <bits/stdc++.h>
using namespace std;
// N<=15
const int INF = 987654321;
int N,ans=INF;
int mp, mf, ms, mv;
int a, b, c, d, sum;
vector<int> info[16];
map<int, vector<vector<int>>>ans_v; // key(cost), value(index조합, 한cost에 여러개의 index조합이 있을 수 있다)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++) {
		int p, f, s, v, cost;
		cin >> p >> f >> s >> v >> cost;
		info[i].push_back(p);
		info[i].push_back(f);
		info[i].push_back(s);
		info[i].push_back(v);
		info[i].push_back(cost);
	}

	for (int i = 1; i < (1 << N); i++) {
		vector<int>tmp; // index 조합
		a = b = c = d = sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				tmp.push_back(j + 1); // idx_start=0
				a += info[j][0];
				b += info[j][1];
				c += info[j][2];
				d += info[j][3];
				sum += info[j][4]; // cost
			}
		}
		if (a>=mp&& b>=mf&& c>=ms&& d>=mv) { // 조건에 해당된다면
			if (ans >= sum) { // cost_MIN값 갱신
				ans = sum;
				ans_v[ans].push_back(tmp);
			}
		}
		
	}
	if (ans == INF) // cost갱신이 없었는 경우 모든 조건이 만족하지 않음
	{
		cout << -1;
	}
	else {
		sort(ans_v[ans].begin(), ans_v[ans].end()); // index 오름차순 출력을 위함
		cout << ans << "\n"; // cost
		for (int i : ans_v[ans][0])cout << i << " "; // index combi
	}
	

	return 0;
}