#include <bits/stdc++.h>
using namespace std;

// �Ҽ� - 1�� �ڽ����θ� ���� �� �ִ� ��
// �ռ��� - 1�� �ڽ��� �ƴ� ���� ������ ��Ÿ�� �� �ִ� ��

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,X,Y;
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> N;
		X = N * 9; // 9������ ���� ���� Y�� �Ҽ��� ��찡 �ִ�.
		Y = X - N;
		cout << "#"<<i<<" "<<X << " " << Y<<"\n";
	}
	return 0;
}