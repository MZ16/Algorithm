#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int ans = INF;
int N;
int col[42]; // T=1, H=0

void func(int depth) {
	if (depth == N + 1) // ������ depth���
	{
		int sum = 0;
		for (int i = 1; i <= (1 << N-1); i *= 2) { // row binary
			int cnt=0;
			for (int j = 1; j <= N; j++) {
				if (col[j] & i)cnt++; // row 'T' check				
			}	
			sum += min(cnt, N - cnt); // row�� ������
		}
		ans = min(ans, sum);
		return;
	}

	// col
	func(depth + 1);	//�ȵ�����
	col[depth] = ~col[depth];
	func(depth + 1);	//������
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		int value = 1;
		cin >> s;
		for (int j = 0; j < N; j++) { // �� �࿡���� ��Ʈ����ŷ
			if (s[j] == 'T')col[i] |= value;
			value *= 2;
		}
	}

	func(1);
	cout << ans;

	return 0;
}

/*
* N <= 40, O(2^40)
* ���� �Ұ����� �ð����⵵�̹Ƿ� �����Ų��. / ���� ���� �ƴ� �࿡ ���ؼ��� ������ ���� - O(2^20)
* �ุ ������ ���� ���� �����ش� ������ �ִ�.
* ������ �����°��� '~'�����ڸ� ���� ������ �ʿ��� ��Ʈ�� �˻��Ѵ�.
*	������Ʈ�� pc�� bit����ŭ �Ͼ���� ������ �����Ͽ� �ʿ��� �κи� �˻��Ѵ�.
* 
* �ʱ�ȭ
* �࿡���� ��Ʈ����ŷ ���� ���� �迭�� �����.
* 'T'������ ���� 'OR' �����ڷ� �ش� index�� �����Ѵ�. / T=1, H=0
*		ex)	for(int j = 0; j < s.size(); j++){
				if(s[j] == 'T')a[i] |= value; 
				value *= 2;
			}
* if(here==n+1) / ��� ����� ���� ������ depth�� ������ �ϼ����� ����.
*/