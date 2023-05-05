#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int ans;

void dc(int y, int x, int size) {
	if (r == y && c == x) {
		cout << ans;
		return;
	}else if(r >= y && r < y+size && c>=x && c<x+size){ 
		dc(y, x, size / 2);
		dc(y, x+size/2, size / 2);
		dc(y+size/2, x, size / 2);
		dc(y+size/2, x+size/2, size / 2);
	}
	else {
		ans += size * size;
	}
	return;
}

int main() {
	cin >> n >> r >> c;
	dc(0, 0, pow(2, n));
	return 0;
}

/*	4사분면으로 분할정복
*	현재 사분면에 target이 있는지 확인
*	없으면 현재 size만큼 더함, 있다면 분할정복을 통해 target을 찾음
* 
*	else if(r >= y && r < y+size && c>=x && c<x+size)
*	타겟이 존재하는 사분면의 시작과 끝 지점을 나타내는 조건문 target = (r,c) / (y,x) = startPoint / (y+size, x+size) = endPoint
*/