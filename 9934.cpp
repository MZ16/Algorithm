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

/* Inorder의 형태로 탐색하는 문제이다. 
* index기반 binary_Search와 같은 형태로 접근하면 된다
* 조금 다른점은 level별로 답을 출력해야 함으로 그 부분만 조금 수정해주면 쉽게 풀 수 있다.
*/