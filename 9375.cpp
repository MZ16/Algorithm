#include <bits/stdc++.h>
using namespace std;

// ����Ǽ��� �������� �����Ǹ� ������ �Է��� ���÷� �ϸ�
	// headgear = hat + turban + NULL = 3 // eyewear = sunglasses + NULL = 2
	// headgear * eyewear -1(�������� �ƹ��͵� ���������� ����) = 5 ��� ������ �����Ѵ�.
// 
// ����� ���� ���� Ŀ��Ȯ���� �������� ������� long long���� �����ϴ°��� ����.

int TC, N;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		map<string, int> mp;
		cin >> N;
		for (int j = 0; j < N; j++) {
			string a, b; // a�� ����, b�� key��
						// �ش� �������� ������ ������ �ʿ������� key�� ���� ����������
			cin >> a >> b;
			mp[b]++;
		}
		long long ret = 1; // ����� ��
		for (auto a : mp) {
			ret *= (long long)a.second + 1;
		}

		cout << ret - 1<<"\n";
	}

	return 0;
}