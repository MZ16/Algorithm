#include <bits/stdc++.h>
using namespace std;

// �ܼ� ��ȸ
// 1 <= N <= 15,000
// 1 <= M <= 10,000,000
// ���� ��ȣ�� 100,000 ���� �۰ų� ���� �ڿ���
// ���� �� ���߹ݺ��� ��ȸ

int N,M;
int arr[15001];
int cnt = 0;

int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr+N);
	if (M > 200000) cout << 0<<"\n";// ���� ��ȣ�� ������ 100,000 ������ 2���� ���� ������ �� 20���� �ʰ��� �� ���� ������ 
									// �ڵ��� ȿ������ ���� �߰�������, �ش� �������� ��� ����
	else {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (arr[i] + arr[j] == M)cnt++;
			}
		}
		cout << cnt;
	}
	
	
	return 0;
}