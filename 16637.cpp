#include <bits/stdc++.h>
using namespace std;

vector<char> oper; // ������
vector<int> num; // ����
int ans = -987654321;
int N; string s;

int op(char ch, int a, int b) {
	if (ch == '+')return a + b;
	if (ch == '-')return a - b;
	if (ch == '*')return a * b;
}

void go(int h_idx, int h_num) {
	if (h_idx == num.size() - 1) {
		ans = max(ans, h_num);
		return;
	}
	go(h_idx + 1, op(oper[h_idx], h_num, num[h_idx + 1])); // ��ȣX
	if (h_idx + 2 <= num.size() - 1) { // ��ȣO, size check
		// idx0 operator (idx1 operator idx2)
		go(h_idx + 2, op(oper[h_idx], h_num, op(oper[h_idx + 1], num[h_idx + 1], num[h_idx + 2])));
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)num.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}
	go(0, num[0]);
	cout << ans;
	return 0;
}

/* ����Ž��
* �켱������ ���� ������(+,-,*)�̸� ��ȣ�� �߰��Ͽ�(�켱����) �ִ��� ���ϴ� ����
* ��ȣ�� �߰����� �ʰų� �߰��ϰų� 2���� ��͸� ������ ��
* �߰����� �������
*	���簪�� �������� �����ϸ��
* �߰� �� ���
*	1. overflow���� ���ǹ�
*	2. h_idx_num�� operator(h_idx_num+1, h_idx_num+2)�� ���� �������ָ� �� (������)
* 
* //ans�� ������ -2^31 ~ 2^31 �̹Ƿ� ans�� �ּڰ��� ������
*/