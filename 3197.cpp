#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1502;
int R, C, y, x, ans, swanY, swanX;
char arr[MAX][MAX];
int visited_water[MAX][MAX], visited_swan[MAX][MAX];
queue<pii>waterQ, water_tmpQ, swanQ, swan_tmpQ;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Qclear(queue<pii>& q) { // while q.pop보다 빈공간 q와의 swap이 더 빠르다.
	queue<pii>empty;
	swap(q, empty);
	return;
}

void water_melting() {
	while (!waterQ.empty()) {
		tie(y, x) = waterQ.front();
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited_water[ny][nx])continue;
			if (arr[ny][nx] == 'X') {
				visited_water[ny][nx] = 1;
				water_tmpQ.push({ ny,nx }); // water의 다음 좌표 저장
				arr[ny][nx] = '.';
			}
		}
	}
}

int move_swan() {
	while (!swanQ.empty()) {
		tie(y, x) = swanQ.front();
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
			visited_swan[ny][nx] = 1;
			if (arr[ny][nx] == '.') { swanQ.push({ ny,nx }); }
			else if (arr[ny][nx] == 'X') { swan_tmpQ.push({ ny,nx }); } // swan의 다음좌표 저장
			else if (arr[ny][nx] == 'L')return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			// 아래 처럼 설정 시 L이 두개이므로 문제가 생긴다.
			//if (arr[i][j] == 'L') { visited_swan[i][j] = 1; swanQ.push({ i,j }); } 
			if (arr[i][j] == 'L') { swanY = i; swanX = j; }
			if (arr[i][j] == '.' || arr[i][j] == 'L') { visited_water[i][j] = 1; waterQ.push({ i,j }); } // 물 초기값 설정(백조도 물 위에있음)
		}
	}
	visited_swan[swanY][swanX] = 1; swanQ.push({ swanY,swanX }); // 백조 초기값 설정
	while (1) {
		if (move_swan())break; // true반환 시 백조가 만남
		water_melting();
		swanQ = swan_tmpQ; // 저장해둔 백조의 다음 초기값
		waterQ = water_tmpQ; // 저장해둔 물의 초기값(빙하가 녹은지점)
		Qclear(swan_tmpQ);
		Qclear(water_tmpQ);
		ans++;
	}
	cout << ans;
	return 0;
}



/* flood fill (qSize가 아닌 temp를 통해 한다 이것이 정석)
* 초기값 저장을 위해 입력받으면서 '.'과 'L'의 좌표를 저장한다.
* water_melting()
*	물의 초기좌표는 모두 visited상태이며 해당q(waterQ)에 초기값이 모두 들어가있다.
*	물 옆의 X좌표를 체크 및 방문처리 후 X를 '.'으로 바꾼다.
* move_swan()
*	백조의 초기좌표는 visited상태이며 해당 q(swanQ)에 초기좌표값이 들어있다
*	'.'일 경우는 해당 q(swanQ) push를 통해 계속 이동가능 하게 함
*	'X'일 경우 백조의 다음 초기 좌표값이므로 스왑용 q(swan_tmpQ)에 저장해 둔다.
*		다른 q에 저장하였으므로 bfs의 무한루프를 막는다.
*	'L'일 경우 다른 백조를 만난것이므로 return true;를 해준다.
* 
* 해당 문제에서 못만나는 경우는 없기 때문에 무한루프에 기저조건을 설정하여 만날때 까지 반복한다.
*/