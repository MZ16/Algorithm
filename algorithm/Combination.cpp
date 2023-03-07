#include <bits/stdc++.h>
using namespace std;

// 조합 - 순서상관없이 뽑는 경우의 수
// nCr = n! / r!(n-r)!

int a[5] = { 1,2,3,4,5 };
int n = 5, r=3;

void combi(int start, vector <int> v) {
	if (v.size() == r) {
		for (auto i : v)cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = start + 1; i < n; i++) { // 0번쨰 idx를 push 후 재귀에는 다음idx값을 넘겨주기 위해 (start=-1) + 1
		v.push_back(a[i]);
		combi(i, v);
		v.pop_back();
	}

	return;
}


int main() {
	// 중첩 for문을 활용한 combination(조합), r의 갯수만큼 중첩해주면 된다.
	
	// 
	// 5C3, 내림차순
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				cout << a[i] << " " << a[j] << " " << a[k] << "\n";
			}
		}
	}cout << "\n";

	// 오름차순
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				cout << a[i] << " " << a[j] << " " << a[k] << "\n";
			}
		}
	}cout << "\n";

	// 재귀 , r - 조합할 갯수
	vector <int> v;
	combi(-1, v);

	return 0;
}