#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	vector <int> v;
	cin >> N;
	for (int x,i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	printf("%d", v[N / 2]);
}