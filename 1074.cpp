#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int ans;

void dc(int y, int x, int size) {
	if (r == y && c == x) {
		cout << ans;
		return;
	}else if(r >= y && r < y+size && c>=x && c<x+size){ 
		dc(y, x, size / 2);
		dc(y, x+size/2, size / 2);
		dc(y+size/2, x, size / 2);
		dc(y+size/2, x+size/2, size / 2);
	}
	else {
		ans += size * size;
	}
	return;
}

int main() {
	cin >> n >> r >> c;
	dc(0, 0, pow(2, n));
	return 0;
}

/*	4��и����� ��������
*	���� ��и鿡 target�� �ִ��� Ȯ��
*	������ ���� size��ŭ ����, �ִٸ� ���������� ���� target�� ã��
* 
*	else if(r >= y && r < y+size && c>=x && c<x+size)
*	Ÿ���� �����ϴ� ��и��� ���۰� �� ������ ��Ÿ���� ���ǹ� target = (r,c) / (y,x) = startPoint / (y+size, x+size) = endPoint
*/