#include <bits/stdc++.h>
using namespace std;

int L, N, ans;
int a[102][102], b[102][102]; // ����, ����

void solve(int arr[102][102]) {
	for (int i = 0; i < N; i++) {
		int j,cnt=1;
		for (j = 0; j < N - 1; j++){ // j+1�� üũ�ϱ� ���� N-1
			if (arr[i][j] == arr[i][j + 1])cnt++; // ���̰� ����
			else if (cnt >= L && arr[i][j] + 1 == arr[i][j + 1])cnt = 1; // ������
			else if (cnt >= 0 && arr[i][j] - 1 == arr[i][j + 1])cnt = (-L + 1); // ������
			else break;
		}
		// �������� �������� �ϳ��� ������ ǥ���ϱ� ���� �������� ������ �����Ͽ���
		// ���� ��ġ�� �����ؾ��ϴ� 1 �Ǵ� -L+1�� �����ߴ�.

		if (j+1 == N && cnt >= 0)ans++; // ������ ������ ��Ǵ� ���� ����
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j]; // ���� �迭�� ���η�
		}
	}
	solve(a); solve(b);
	cout << ans;
	return 0;
}