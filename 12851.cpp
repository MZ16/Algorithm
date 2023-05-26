#include <bits/stdc++.h>
using namespace std;
// 0 <= N,K <= 100,000 / N*2�� �̵��� �����ϹǷ� overflow������ ���� �ִ����*2���� check
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
			else if (visited[next] == visited[now] + 1) { // next�� �湮������ ����ġ�� ���� �ٸ� ������ �ִٸ�
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
/* visited - ����idx ����ġ, cnt_visited - ����idx ����ġ ����
* �ִܰŸ��� �ִܰŸ��� ������ ���ϴ� �����̴�. ������ �������� �����Ǹ� for-each�� Ȱ���Ѵ�.
* for-each�� map�� dy,dx�� ����ϱ� ���� ��� �ٸ����·� �����ص� �����ϴ�.
* ��ǥ������ ����ġ�� ���� ���� ���� �湮�Ͽ� ����ġ�� �������� ��ǥ������ �湮�� �� ����.
* ������ �������� �����Ǵ� bfs�� �̵����� ���������� �迭�� ������ bfs�� �ٸ���.
*/