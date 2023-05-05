#include <bits/stdc++.h>
using namespace std;

void Hanoi(int val, int A, int B, int C) {
	if (val == 1) {
		cout << A << " " << C << "\n";
	}
	else {
		Hanoi(val - 1, A, C, B);
		cout << A << " " << C << "\n";
		Hanoi(val - 1, B, A, C);
	}

	return;
}

int main() {
	int N;
	cin >> N;
	string ret = to_string(pow(2, N));
	int tmp = ret.find('.');
	ret = ret.substr(0, tmp);
	ret[ret.size() - 1] -= 1;
	cout << ret << "\n";
	if (N <= 20) Hanoi(N, 1, 2, 3);

	return 0;
}
// A B C / A C B / B A C / AC
// 실행 횟수 = pow(2,N)-1
// pow는 double 형이며 N이 20이상일 경우 int로 표현할 수 없다.
// string으로 받아 find와 substr로 정수만 추출하고 마지막 인덱스에 -1을 해준다.