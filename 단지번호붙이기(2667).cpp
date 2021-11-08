#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define MAX_LEN 26
using namespace std;

int N,cnt;
typedef pair<int, int> pii;
int map[MAX_LEN][MAX_LEN];
vector <int> v; // Ä­¼ö ÀúÀå
bool visited[MAX_LEN][MAX_LEN];
int dyx[4][2] = { {1,0},{-1,0},{0,-1},{0,1} }; // »óÇÏÁÂ¿ì

void bfs(int y, int x) {
	cnt++;
	visited[y][x] = true;
	queue<pii> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dyx[i][0];
			int nx = x + dyx[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == 0 || visited[ny][nx])continue;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
			cnt++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j]-'0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1&&!visited[i][j]) {
				cnt = 0;
				bfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)cout << v[i] << "\n";
	return 0;
}