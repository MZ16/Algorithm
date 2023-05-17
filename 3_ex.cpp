#include<bits/stdc++.h>
using namespace std;

// �־��� N���� �� �� mod 11�� ���� �� ���� ū ���� ���� ���϶�

int ans,N;
int cnt;
vector<int> v;
const int mod = 11;

void go(int idx, int sum) {
	if (ans == 10)return; // ����� ���� �����ϱ� ����
	if (idx == N) {
		cnt++; // ����Ƚ�� ������� ����
		ans = max(ans, sum % mod);
		return;
	}
	go(idx + 1, sum + v[idx]); // ����
	go(idx + 1, sum); // ���Ծ���
}


int main() {
	cin >> N;
	for (int x, i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	go(0,0);
	cout << cnt << "\n";
	cout << ans;
	return 0;
}
/* N=10�̹Ƿ� 2^10 = 1024��ŭ ������, ���ʿ��� Ž���� ���ٴ°��� �� �� ����
* 11 mod�� �ϸ� �ִ��� 10�̶�� ���� �� �� ���� �� ���� ���� ����� ���� �����ϴ°��� ��Ʈ��ŷ
* if(ans==10)return;�� ����Ǽ��� �����Ͽ� cnt�� 0�� ������ ���� �� �� �ִ�.
*/