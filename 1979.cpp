#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// ��� �ܾ �� �� ������
/* ���� ����, ���ο� ���� ��ĭ�� Ȯ���Ѵ�
* 1. ���ΰ� 1�϶� ��ĭ������ ������Ű�� 
	 ��ı������ K���� ũ�ٸ� ��ĭ�� 0���� �ʱ�ȭ
	 idx�� ���̰� ��ĭ������ K�� ���ٸ� ans�� ������Ŵ
  2. ���ΰ� 0�϶� ��ĭ������ K�� ���ٸ� ans�� ������Ŵ
	 ��ĭ������ 0���� �ʱ�ȭ
* 3. ���ε� ���� ��������
*/

int main() {
	int TC, N, K;
	cin >> TC;
	for (int x = 1; x <= TC; x++) {
		int arr[15][15];
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		
		
		int ans = 0;
		
		//����
		for (int i = 0; i < N; i++) {
			int colCnt = 0;
			for (int j = 0; j < N; j++) {
				if (arr[i][j]) { // 1�� ���
					colCnt++;
					if (colCnt > K)colCnt = 0; 
					if (j == N - 1 && colCnt == K)ans++;
				}
				else { // 0�� ���
					if (colCnt == K)ans++;
					colCnt = 0;
				}
			}
		}

		//����
		for (int i = 0; i < N; i++) {
			int rowCnt = 0;
			for (int j = 0; j < N; j++) {
				if (arr[j][i]) { // 1�� ���
					rowCnt++;
					if (rowCnt > K)rowCnt = 0;
					if (j == N - 1 && rowCnt == K)ans++;
				}
				else { // 0�� ���
					if (rowCnt == K)ans++;
					rowCnt = 0;
				}
			}
		}
		printf("#%d %d\n", x, ans);
		ans = 0;

	}

}