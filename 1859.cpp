#include <iostream>
#include <algorithm>
using namespace std;

/*
1. max���� ���Ѵ�, �ʱⰪ�� ������ index�̸� �ڿ������� ���������� ���Ѵ�
2. max�� �迭 �ε������� ũ�ų� ������� ans�� ���Ѵ�
	-������쵵 ���Խ�Ű�� ������ �ƹ� ������ �����ʴ°Ͱ� ���⶧��, ���Խ�Ű�� �ʾƵ� ������.
3. max�� �迭 �ε������� ������� max�� �������ش�.
*/
int arr[1000001];

int main() {
	int TC, N;
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) cin >> arr[j];
		int max = arr[N - 1]; // ������ idx�� �ʱ�ȭ
		long long ans = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (max >= arr[j]) ans = ans + (max - arr[j]);
			else max = arr[j]; // max�� ����
		}
		cout << "#" << i+1 << " " << ans << "\n";
	}
	return 0;
}