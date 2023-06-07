#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string A;
	int ans = 0;
	cin >> A;
	
	for (int i = 0; i < A.size(); i++) {
		if (A[i] >= 'A' && A[i] <= 'F') {
			ans = (ans * 16) + (A[i] - 'A'+10);
		}else if (A[i] >= 'a' && A[i] <= 'f') {
			ans = (ans * 16) + (A[i] - 'a' + 10);
		}
		else if (A[i] >= '0' && A[i] <= '9') {
			ans = (ans * 16) + (A[i] - '0');
		}
	}
	cout << ans;

	return 0;
}