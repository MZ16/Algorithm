#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAX_LEN 101
using namespace std;

typedef pair<int, int> pii;
//상하좌우 위아래
int dyxz[6][3] = { {1,0,0},{-1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };
bool visited[MAX_LEN][MAX_LEN][MAX_LEN];
int map[MAX_LEN][MAX_LEN][MAX_LEN];
int M, N, H,day=-1;
queue<pair<pii, int>> q;


void bfs() {
	while (!q.empty()) {
		int size = q.size();
		day++;
		for (int i = 0; i < size; i++) {
			int z = q.front().first.first;
			int y = q.front().first.second;
			int x = q.front().second;	
			q.pop();
			for (int j = 0; j < 6; j++) {
				int nz = z + dyxz[j][2];
				int ny = y + dyxz[j][0];
				int nx = x + dyxz[j][1];
				if (nz < 0 || ny < 0 || nx < 0 || ny >= N || nx >= M || nz >= H || visited[nz][ny][nx])
					continue;
				q.push(make_pair(make_pair(nz, ny), nx));
				visited[nz][ny][nx] = true;
			}			
		}
	}
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[k][i][j]) {
					cout << "-1";
					return;
				}									
			}
		}
	}
	cout << day;

}

int main() {
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 1 || map[k][i][j] == -1)
					visited[k][i][j] = true;
				if (map[k][i][j] == 1)
					q.push(make_pair(make_pair(k, i), j));
			}
		}
	}
	bfs();
	

	return 0;
}