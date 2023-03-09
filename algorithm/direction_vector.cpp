#include <bits/stdc++.h>
using namespace std;

// 맵과 방향벡터

//	Q. 3 * 3 맵을 입력받아야 함.이 맵은 1과 0으로 이루어져있고{ 0, 0 }은 무조건 1임을 보장한다. {0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며 
//	방문한 정점은 다시 방문하지 않으며 방문하는 좌표를 출력하는 코드. 0은 갈 수 없는 지역. 1은 갈 수 있는 지역을 구현하시오.


// 상하좌우 (통상적으로 하,우,상,좌 순으로 작성하는것이 좋다.)
//int dy[4] = { 1,-1,0,0 };
//int dx[4] = { 0,0,-1,0 };

int visited[3][3]; int arr[3][3];

// 하우상좌
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

// 좌표 y,x
void go(int y, int x) {
	visited[y][x] = 1;
	cout << y << ":" << x << "\n";
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny>3 || nx < 0 || nx>3)continue; // map의 범위 초과
		if (arr[ny][nx] == 0) continue; // 0으론 이동할 수 없음
		if (visited[ny][nx]) continue;
		
		go(ny, nx);
	}
	return;
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	go(0, 0);

	

	return 0;
}
