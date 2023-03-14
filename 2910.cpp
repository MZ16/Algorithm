#include <bits/stdc++.h>
using namespace std;

// custom operator�� �ٽ�
// �� �������� C�� ������ 10���̴�.�׷��� idx��� ī���ù迭 ���� �� 
// Array�� vector�� Ž�� �� O(n)�� �ð��� �ɸ��� ������ O(log n)�� map�� ����ϴ°��� �����ϴ�
// map�� ������ �Ͽ��� ��Ұ� ����, 

/* �ް���
*	mp			- (first - ����), (second - ����)		/	ī���ù迭
* mp_first		- (first - ����), (second - ����idx)	/	���� ���� ����
*	v			- (first - ����), (second - ����)		/	custom operator ����
* bool type
*/

// �켱���� 
// 1. �� ��
// 2. ���� �Էµ� ��(�� ���� ������� ����)
typedef pair<int, int> pii;
vector<pii> v;
map<int, int> mp, mp_first;
int N, C;

bool cmp(pii a, pii b) {
	if (a.first == b.first) return mp_first[a.second] < mp_first[b.second]; // a�� ���� ���� ������ ������ true
	return a.first > b.first; // a�� �󵵼��� ũ�� true
}

int main() {
	cin >> N >> C;
	for (int idx,i = 1; i <= N; i++) {
		cin >> idx;
		mp[idx]++;
		if (mp_first[idx] == 0)mp_first[idx] = i; // i�� 0���� �ϸ� map�� Ư���� �������ص� ��Ұ� ����� �� ������ ���ǹ� ������ ������ ����
	}
	
	for (auto i : mp) v.push_back({ i.second, i.first });

	sort(v.begin(), v.end(), cmp);

	for (auto i : v) 
		for (int j = 0; j < i.first; j++) cout << i.second << " ";
	
	return 0;
}