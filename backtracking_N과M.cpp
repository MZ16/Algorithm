#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v;
vector<int> v2; // �ߺ� ���Ÿ� ����
int visited[10];
int arr[10004]; // dfs_5

void dfs_1(int depth); // ���� ������� ��� ����
void dfs_2(int depth); // ���� (�ߺ����� ����)
void dfs_3(int depth); // ���� ������� ��� ����2 (���� ���� ������ ��� ��)
void dfs_4(int depth); // (i, i>=j)�� �����ϴ� ��� ����
void dfs_5(int depth); // �־��� ������ (i, j!=i)�� �����ϴ� ��� ����
void dfs_6(int depth); // �־��� ���� ����
void dfs_7(int depth); // �־��� ���� ��� ����
void dfs_10(int depth); // �ߺ�����

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

void dfs_1(int depth) { // N��M(1)
	// ���� ������� ��� ����
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
