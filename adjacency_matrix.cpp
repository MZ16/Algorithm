#include <bits/stdc++.h>
using namespace std;

// ���� 0 ~ 9, ���� 1-2 / 1-3 / 3-4
// 0������ �湮 ���� ��带 ã�� �ش� ������ �湮, ����� ��带 �̾ �湮�ϴ� ����Լ�
int adj[10][10];
int visit[10] = { 0, };

void dfs(int i) {
	visit[i] = 1;
	cout << "���� :  " << i <<"\n";
	for (int j = 0; j < 10; j++) {	// ����� ����ó��
		if (visit[j])continue;
		if (adj[i][j]) {
			cout << "���� :  " << i<< "-"<<j << "\n";
			dfs(j);
		}
	}
	return;
}


int main() {

	adj[1][2] = 1;	adj[1][3] = 1;	adj[3][4] = 1;
	adj[2][1] = 1;	adj[3][1] = 1;	adj[4][3] = 1;
	
	
	// �� ����Լ����� ����� �������� ���°��̶� ������� �ʴ� ������ �湮���� �ʴ´ٴ°� �����ؾߵ�
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (adj[i][j] && !visit[i]) {
				dfs(i);
			}
		}

	}
	return 0;
}