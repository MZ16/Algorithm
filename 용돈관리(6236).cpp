#include <iostream>

using namespace std;
int n, m;
int map[100100];
bool check(int val) {
	int money = val;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (map[i] > val) {
			return false;
		}
		


		if (money >= map[i]) {
			money -= map[i];
		}
		else {
			money = val;
			money -= map[i];
			cnt++;
		}

	
	}
	if (cnt <= m) return true;
	else return false;

}
int main() {
	scanf("%d%d", &n, &m);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[i]);
		sum += map[i];
	}
	int low = 0;
	int high = sum;
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (check(mid)) {
			ans = mid;
			high = mid - 1;
		}
		
		else {
			low = mid + 1;
		}
	}
	cout << ans << endl;
}