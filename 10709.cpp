#include <bits/stdc++.h>
using namespace std;

// 1 <= H,W <= 100 ������ �۾� �ݺ������� �ذ�
// (i,j) = c �ϰ�� check�� flag, ret, idx�� �ʱ�ȭ��Ŵ
// 'c'�� �ƴ����� flag = true�� ������ �̵� �����ϸ� �̵� �Ÿ��� ���ϱ����� idx++

int main() {
	int N, M;
	char c[102][102];	 
	int ret[102][102];
	memset(ret, -1, sizeof(ret));
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {			
			cin >> c[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		int flag = 0;
		int idx = 0;
		for (int j = 0; j < M; j++) {
			if (c[i][j] == 'c')flag = 1, ret[i][j]=0,idx=0; // ������ �̵� �� �� ������ �˸��� ���� flag=1 ���� ��� 0���� �ʱ�ȭ
			else if (flag)idx++, ret[i][j] = idx;	//'c'�� �ƴϸ鼭 ������ �̵� ����
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ret[i][j] << " ";
		}cout << "\n";
	}
	return 0;
}