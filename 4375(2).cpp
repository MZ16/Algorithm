#include <bits/stdc++.h>
using namespace std;

// 1�� ������ �ּڰ��� N�� �������� ����ϴ� �ڵ��̴�.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    while (cin >> N) {
        int arr[10000];
        int i = 0;
        long long cnt = 1;
        int ret = 1;
        while (cnt % N != 0) {
            arr[i++]= (cnt * 10 + 1) / N;
            cnt = (cnt * 10 + 1) % N;
            ret++;
        }
        cout << "�� �ڸ����� ��� 1�� �̷���� ���� ���� ���� " << string(ret, '1') << "�̸�, " << "\n";
        cout << "����� : "; for (int j = 0; j < ret-1; j++) cout << arr[j];
        
    }
    return 0;
}
