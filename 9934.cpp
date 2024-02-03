#include <bits/stdc++.h>
using namespace std;

vector<int> level[12];
int K;
int arr[1026];

void binarySearch(int start, int end, int depth) {
	if (start > end)return;
	if (start == end) {
		level[depth].push_back(arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	
	level[depth].push_back(arr[mid]);
	
	binarySearch(start, mid, depth+1);
	binarySearch(mid+1, end, depth+1);
	return;
}

int main() {

	cin >> K;
	for (int i = 0; i < pow(2,K)-1; i++)cin >> arr[i];
	binarySearch(0, pow(2,K)-1, 0);

	for (int i = 0; i < K; i++) {
		for (int j : level[i]){
			cout << j<<" ";
		}cout << "\n";
	}

	return 0;
}

/* Inorder�� ���·� Ž���ϴ� �����̴�. 
* index��� binary_Search�� ���� ���·� �����ϸ� �ȴ�
* ���� �ٸ����� level���� ���� ����ؾ� ������ �� �κи� ���� �������ָ� ���� Ǯ �� �ִ�.
*/