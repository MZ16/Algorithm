#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int TC,total,max=0;
	vector <int> v;
	cin >> TC;
	for (int x, i = 0; i < TC; i++) {
		cin >> x;
		v.push_back(x);
		max = max < x ? x : max;
	}cin >> total;
	int start = 1, end=max;
	int sum, ans;
	while (start <= end) {
		int mid = (start + end) / 2;
		sum = 0;
		for (int i = 0; i < TC; i++) sum += min(mid, v[i]);
		if (total >= sum) {
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;		
	}
	cout << ans;
	return 0;
}