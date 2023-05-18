#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii>v; // ��� ���� ��ǥ
int arr[54][54];
int N, L, R;
int visited[54][54];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans,flag=1;

void bfs(int y, int x) {
	queue<pii> q;
	int pCnt = arr[y][x]; // �����ο�
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];			
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])continue;
			int tmp = abs(arr[y][x] - arr[ny][nx]);
			if (tmp >= L && tmp <= R) {
				flag = 1; // ���� ���θ� �Ǵ�
				visited[ny][nx] = 1;
				pCnt += arr[ny][nx];
				q.push({ ny,nx });
				v.push_back({ ny,nx });
			}
		}		
	}

	// ���� �α� ����
	if(v.size()>=2)
		for (int i = 0; i < v.size(); i++) arr[v[i].first][v[i].second] = pCnt / v.size();

		
	
	
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (flag) {
		flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					v.push_back({ i,j }); // �ʱⰪ
					bfs(i, j);					
				}

				/*for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						cout << arr[i][j] << " ";
					}cout << "\n";
				}cout << "\n";*/
			}

		}
		if (flag)ans++;
		memset(visited, 0, sizeof(visited));
		
	}
	
	cout << ans;
	return 0;
}
/*
* 
1. ���漱�� �����ϴ� �� ������ �α� ���̰� L�� �̻�, R�� ���϶��, �� ���� �����ϴ� ���漱�� ���� �Ϸ� ���� ����.
2. ���� ���ǿ� ���� ������ϴ� ���漱�� ��� ���ȴٸ�, �α� �̵��� �����Ѵ�.
3. ���漱�� �����־� ������ ĭ���� �̿��� �̵��� �� ������, �� ���� ���� �Ϸ� ������ �����̶�� �Ѵ�.
4. ������ �̷�� �ִ� �� ĭ�� �α����� (������ �α���) / (������ �̷�� �ִ� ĭ�� ����)�� �ȴ�. ���ǻ� �Ҽ����� ������.
5. ������ ��ü�ϰ�, ��� ���漱�� �ݴ´�.
*/

/* ����
- flag�� ����� �߸���, �־��� �迭 ��ü�� �ѽ���Ŭ�� ���ƾ��ϴµ� �� ��ǥ�� bfs�θ� flag�� �Ǵ��ϰ� ans���� ����������

- ������ �߸� ������, �� ������ bfs�� ���� ������ �Ͼ�� ���� ���������� visit�� �ʱ�ȭ �� �� 
	���ŵ� ������ �ٽ� ���� �����ϴ� �� �˰� �ۼ���

- �湮�� ������ �ٽ� �湮���� ������ �迭 ��ü�� bfs�� ���� day�� ������Ų��.
- �� ����Ŭ�� ������ �湮�迭�� �ʱ�ȭ�Ѵ�.
*/