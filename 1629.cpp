#include <bits/stdc++.h>
using namespace std;

// A,B,C�� �� �� 21������� ���� ���� �� �����Ƿ� ������������ �߰� �ɰ� ���� �Ѵ�.
// A^B%C


typedef long long ll;

ll power(ll A, ll B, ll C) {
	if (B == 0) return 1;		// ������ 0�� ��
	if (B == 1) return A % C;	// ������ 1�� ��

	ll ret = power(A, B / 2, C);// ����
	ret = (ret * ret) % C;		// ���� ó�� 2^10 = 2^5 * 2^5
	if (B % 2) ret = (ret * A) % C;	// Ȧ���� ���
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll A, B, C;
	cin >> A >> B >> C;
	cout << power(A, B, C);


	return 0;
}