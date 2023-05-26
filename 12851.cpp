#include <bits/stdc++.h>
using namespace std;
// 0 <= N,K <= 100,000 / N*2의 이동이 가능하므로 overflow방지를 위해 최대범위*2까지 check
int N, K;
int visited[200004];
int cnt_visited[200004];

void bfs() {
	visited[N] = 1;
	cnt_visited[N] = 1;
	queue<int>q;
	q.push(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : {now - 1, now + 1, now * 2}) {
			if (next < 0 || next>200000) continue;
			if (!visited[next]) {
				visited[next] = visited[now] + 1;
				cnt_visited[next] += cnt_visited[now];
				q.push(next);
			}
			else if (visited[next] == visited[now] + 1) { // next에 방문했지만 가중치가 같은 다른 간선이 있다면
				cnt_visited[next] += cnt_visited[now];
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	if (N == K) {
		cout << 0 << "\n";
		cout << 1;
		return 0;
	}
	bfs();
	cout << visited[K]-1<<"\n";
	cout << cnt_visited[K];
	return 0;
}
/* visited - 현재idx 가중치, cnt_visited - 현재idx 가중치 개수
* 최단거리와 최단거리의 갯수를 구하는 문제이다. 정점과 간선으로 구성되며 for-each의 활용한다.
* for-each는 map의 dy,dx를 대신하기 위해 사용 다른형태로 구상해도 무방하다.
* 목표지점엔 가중치가 낮은 값이 먼저 방문하여 가중치가 높은값은 목표지점을 방문할 수 없다.
* 정점과 간선으로 구성되는 bfs는 이동값과 기저조건이 배열로 구성된 bfs와 다르다.
*/