#include <bits/stdc++.h>
using namespace std;

int mp[3][3] = {
	{10, 20, 21},
	{70, 90, 12},
	{80, 110, 120}
};
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,1,0,-1 };
int visited[3][3];
vector<int> v;

void go(int y, int x) {
	if (y == 2 && x == 2) {
		for (auto i : v) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3 || visited[ny][nx])continue;
		visited[ny][nx] = 1;
		v.push_back(mp[ny][nx]);
		go(ny, nx);
		visited[ny][nx] = 0;
		v.pop_back();
	}
}

int main() {
	visited[0][0] = 1;
	v.push_back(mp[0][0]);
	go(0, 0);

	return 0;
}

/*
* 홍철이는 3 * 3 맵에서 {0, 0} 지점에서 길을 잃어버렸다. 
긍정왕 홍철이는 길을 잃어버린 김에 구걸을 하면서 돈을 모으면서 여행을 가려고 한다. 
목적지는 {2, 2}이며 방문한 정점은 다시 방문할 수 없고 해당 맵에 구걸로 얻을 수 있는 돈들이 있다. 
홍철이는 4방향(상하좌우)로 움직일 수 있다.  {2, 2}까지 간다고 했을 때 이 돈들을 모으는 모든 경우의 수를 출력하여라. 

맵 : 

{10, 20, 21}, 
{70, 90, 12},
{80, 110, 120} 
*/