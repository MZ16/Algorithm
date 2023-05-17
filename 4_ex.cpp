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
* ȫö�̴� 3 * 3 �ʿ��� {0, 0} �������� ���� �Ҿ���ȴ�. 
������ ȫö�̴� ���� �Ҿ���� �迡 ������ �ϸ鼭 ���� �����鼭 ������ ������ �Ѵ�. 
�������� {2, 2}�̸� �湮�� ������ �ٽ� �湮�� �� ���� �ش� �ʿ� ���ɷ� ���� �� �ִ� ������ �ִ�. 
ȫö�̴� 4����(�����¿�)�� ������ �� �ִ�.  {2, 2}���� ���ٰ� ���� �� �� ������ ������ ��� ����� ���� ����Ͽ���. 

�� : 

{10, 20, 21}, 
{70, 90, 12},
{80, 110, 120} 
*/