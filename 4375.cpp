#include <bits/stdc++.h>
using namespace std;

// (a+b) % n = (a%n) + (b%n)
// 1�� �̷���� N�� ����� ã�� ����, N<=10,000 , ��ⷯ ������ �ؾ� overflow�� ������ ����
// 111 = (1 * 10) + 1 -> (11*10) + 1
// �� ���� �ڸ����� �����ϰ� cnt = (cnt*10)+1 �̶�� ������ �������� �� �� �ִ�.
// ��ⷯ ���� �� 0�� �Ǹ� ����̹Ƿ� �� �� �����Ѵ�.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	while (cin >> N) {
		int cnt = 1, ret = 1;
		for(;;) {
			if (cnt%N==0) { // !cnt, cnt==0�� ������ Ʋ�ǽ��ϴ� ����, else������ cnt %= N�� ���� 0�� ���� �ʳ�..?
				cout << ret << "\n";
				break;
			}
			else {
				ret++;
				cnt = (cnt * 10) + 1;
				cnt %= N;				
			}
		}
	}
	return 0;
}