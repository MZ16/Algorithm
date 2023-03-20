#include <bits/stdc++.h>
using namespace std;

// �־��� factorial(N)�� 0 ����
// 2�� 5�� ������ ������� ������ 10�̶�� ����� �ݵ�� ���Եȴ�.
//		ex) 100 = 10^2, 100 = (2*5)^2, 20 = 2^2*5
// �� 10���� ������ �������� ���� 2�� 5�� ����� ��� �����ִ�.

// 10�� 2�� 5�� ���� �� �����Ƿ� N!�� 0 ������ 2�� 5�� ���� �� ���� ���� ����.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, N;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int ret2 = 0, ret5 = 0;		
		cin >> N;
		for (int j = 2; j <= N; j *= 2)
			ret2 += N / j;
		for (int j = 5; j <= N; j *= 5)
			ret5 += N / j;
		cout << min(ret2, ret5)<<"\n";
		
	}

	return 0;
}