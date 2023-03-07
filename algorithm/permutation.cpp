#include <bits/stdc++.h>
using namespace std;

vector<int> v;


void make_permutation(int n, int r, int depth) {
	//cout << "n : " << n << " r :" << r << " depth : " << depth << "\n";
	if (r == depth) {
		for (int i = 0; i<n; i++)cout << v[i] << " ";
		cout << "\n";
		
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]);
		make_permutation(n, r, depth+1);
		swap(v[i], v[depth]);
	}
	return;
}

int main() {
	
	int N;
	cin >> N;
	for (int x, i = 0; i < N; i++) { cin >> x; v.push_back(x); }

	// 함수를 이용한 순열
	do {
		for (auto i = v.begin(); i != v.end(); i++) cout << *i<<" ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	cout << "\n\n";

	// 재귀를 이용한 순열
	make_permutation(N, N, 0);
	return 0;
}