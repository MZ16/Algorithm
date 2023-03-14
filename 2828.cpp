#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M,J;
	int L = 1, R;// 바구니 왼,오
	int ret = 0;
	cin >> N >> M;
	cin >> J;
	for (int tmp,i = 0; i < J; i++) {
		cin >> tmp;
		R = L + M - 1; // R바구니는 L의 위치에 따라 유동적이다.
		if (tmp >= L && tmp <= R)continue;
		else {
			if (tmp<L) { // 사과위치가 바구니보다 왼쪽에 있을경우
				ret += (L - tmp);
				L = tmp; // L바구니 이동
			}
			else { // 사과위치가 바구니보다 오른쪽에 있을경우, 각 각 이동거리를 더해줌
				L += (tmp - R);
				ret += (tmp - R);
			}
		}
	}
	cout << ret;
	return 0;
}