#include <bits/stdc++.h>
using namespace std;

// 666�� key������ ��� to_string.find�� ���ԉ���� Ȯ��

int main() {
	int N;
	int idx = 666;
	cin >> N;
	while (1) {		
		if (to_string(idx).find("666") != string::npos)N--;
		if (!N)break;
		idx++;
	}
	cout << idx;
	return 0;
}