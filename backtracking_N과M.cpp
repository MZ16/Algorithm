#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v;
vector<int> v2; // 중복 제거를 위함
int visited[10];
int arr[10004]; // dfs_5

void dfs_1(int depth); // 순서 상관없는 모든 조합
void dfs_2(int depth); // 순열 (중복없는 조합)
void dfs_3(int depth); // 순서 상관없는 모든 조합2 (같은 수를 여러번 골라도 됨)
void dfs_4(int depth); // (i, i>=j)를 만족하는 모든 조합
void dfs_5(int depth); // 주어진 수에서 (i, j!=i)를 만족하는 모든 조합
void dfs_6(int depth); // 주어진 수의 순열
void dfs_7(int depth); // 주어진 수의 모든 조합
void dfs_10(int depth); // 중복제거

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	//dfs_1(0);
	//dfs_2(0);
	//dfs_3(0);
	//dfs_4(1);

	//dfs_5
	for (int i = 0; i < N; i++)cin >> arr[i];
	sort(arr + 0, arr + N);
	//dfs_5(0);
	//dfs_6(0);
	//dfs_7(0);
	dfs_10(0);
	return 0;
}

void dfs_1(int depth) { // N과M(1)
	// 순서 상관없는 모든 조합
	if (v.size() == M) {
		for (auto i : v)cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i])continue;
		v.push_back(i);
		visited[i] = 1;
		dfs_1(depth + 1);
		visited[i] = 0;
		v.pop_back();
	}
	return;
}
void dfs_2(int depth) {
	if (v.size() == M) {
		for (auto i : v)cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = depth + 1; i <= N; i++) {
		if (visited[i])continue;
		v.push_back(i);
		visited[i] = 1;
		dfs_2(i);
		visited[i] = 0;
		v.pop_back();
	}
	return;
}
void dfs_3(int depth) {
	if (v.size() == M) {
		for (auto i : v)cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		dfs_3(i);
		v.pop_back();
	}

}
void dfs_4(int depth) {
	if (v.size() == M) {
		for (auto i : v)cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = depth; i <= N; i++) {
		v.push_back(i);
		dfs_4(i);
		v.pop_back(); 
		
	}
	return;
}
void dfs_5(int depth) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++) 
			cout << arr[v[i]] << " ";
		cout << "\n";
		return;
	}
	
	for (int i = depth; i < N; i++) {
		if (visited[i])continue;
		visited[i] = 1;
		v.push_back(i);
		dfs_5(depth);
		v.pop_back();
		visited[i] = 0;
	}
	
}
void dfs_6(int depth) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[v[i]] << " ";
		}cout << "\n";
		return;
	}

	for (int i = depth; i < N; i++) {
		if (visited[i])continue;
		visited[i] = 1;
		v.push_back(i);
		dfs_6(i);
		v.pop_back();
		visited[i] = 0;
	}
	return;
}
void dfs_7(int depth) {
	if (v.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[v[i]] << " ";
		}cout << "\n";
		return;
	}

	for (int i = depth; i < N; i++) {
		v.push_back(i);
		dfs_7(depth);
		v.pop_back();
	}
	return;
}
void dfs_10(int depth) {
	if (v.size() == M) {
			for (int i = 0; i < M; i++) {
				cout << arr[v[i]] << " ";
			}cout << "\n";
			
		return;
	}
	int flag = 0;
	for (int i = depth; i < N; i++) {
		if (!visited[i] && arr[i] != flag) {
			visited[i] = 1;
			v.push_back(i);
			flag = arr[i];
			dfs_10(i);
			visited[i] = 0;
			v.pop_back();
		}
		
	}
	return;
}
