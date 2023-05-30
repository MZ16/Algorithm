#include <bits/stdc++.h>
using namespace std;

int N, ans;
int col[15];

int chk(int depth) {
	for (int i = 0; i < depth; i++)
		if (col[depth] == col[i] || abs(col[depth] - col[i]) == depth - i) return 0;
	return 1;
}

void go(int depth) {
	if (depth == N)ans++;
	else {
		for (int i = 0; i < N; i++) {
			col[depth] = i;
			if (chk(depth))
				go(depth+1);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	go(0);
	cout << ans;


	return 0;
}


/* �� �࿡�� ��ȿ�� �˻縦 ���� �� �����ϴٸ� ���� depth�� ���
*	1. �밢�� = �� ���� +-depth���̹Ƿ� �������� ó�����ش� / abs(col[depth]-col[i]) == depth-i
*	2. ������ - �� ����� ���� ������ �������̴� / col[depth] == col[i]
*	�� ������ �����ϸ� ���� �� �� ����.
* ��ȿ�� ���� N���� �ƴ϶�� ���ƿͼ� �ش� depth�� ���� ������ �����Ѵ�.
*/