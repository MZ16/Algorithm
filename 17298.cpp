#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int ans[1000001];
vector<int> s; // index ����
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	memset(ans, -1, sizeof(ans)); // �ʱⰪ -1
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		while (s.size() && arr[s.back()] < arr[i]) {
			ans[s.back()] = arr[i]; s.pop_back();
		}
		s.push_back(i);
	}

	for (int i = 0; i < N; i++)cout << ans[i] << " ";
	return 0;
}

/*
- ���� brute force�� ��� 1��, õ�������� ������ �������� �ش� ������ 100�� * 100������ �ȵȴ�.
- ������ ���� �ذ��Ͽ� �ð����⵵�� ���δ�.
- stack, vector���� ����� �� size()�� �켱 Ȯ������ ������ �޸����� ������ �߻����� �����Ѵ�.
*/