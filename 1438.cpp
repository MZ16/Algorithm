#include <bits/stdc++.h>
using namespace std;

// 666을 key값으로 잡고 to_string.find로 포함됬는지 확인

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