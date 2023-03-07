#include <bits/stdc++.h>
using namespace std;

// ���� - ����������� �̴� ����� ��
// nCr = n! / r!(n-r)!

int a[5] = { 1,2,3,4,5 };
int n = 5, r=3;

void combi(int start, vector <int> v) {
	if (v.size() == r) {
		for (auto i : v)cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = start + 1; i < n; i++) { // 0���� idx�� push �� ��Ϳ��� ����idx���� �Ѱ��ֱ� ���� (start=-1) + 1
		v.push_back(a[i]);
		combi(i, v);
		v.pop_back();
	}

	return;
}


int main() {
	// ��ø for���� Ȱ���� combination(����), r�� ������ŭ ��ø���ָ� �ȴ�.
	
	// 
	// 5C3, ��������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				cout << a[i] << " " << a[j] << " " << a[k] << "\n";
			}
		}
	}cout << "\n";

	// ��������
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				cout << a[i] << " " << a[j] << " " << a[k] << "\n";
			}
		}
	}cout << "\n";

	// ��� , r - ������ ����
	vector <int> v;
	combi(-1, v);

	return 0;
}