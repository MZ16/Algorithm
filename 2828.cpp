#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M,J;
	int L = 1, R;// �ٱ��� ��,��
	int ret = 0;
	cin >> N >> M;
	cin >> J;
	for (int tmp,i = 0; i < J; i++) {
		cin >> tmp;
		R = L + M - 1; // R�ٱ��ϴ� L�� ��ġ�� ���� �������̴�.
		if (tmp >= L && tmp <= R)continue;
		else {
			if (tmp<L) { // �����ġ�� �ٱ��Ϻ��� ���ʿ� �������
				ret += (L - tmp);
				L = tmp; // L�ٱ��� �̵�
			}
			else { // �����ġ�� �ٱ��Ϻ��� �����ʿ� �������, �� �� �̵��Ÿ��� ������
				L += (tmp - R);
				ret += (tmp - R);
			}
		}
	}
	cout << ret;
	return 0;
}