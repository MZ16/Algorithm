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
        long long num = 1;
        int cnt = 1;
        while (num % N != 0) {
            arr[i++]= (num * 10 + 1) / N;
            num = (num * 10 + 1) % N;
            cnt++;
        }
        cout << "�� �ڸ����� ��� 1�� �̷���� ���� ���� ���� " << string(cnt, '1') << "�̸�, " << "\n";
        cout << "����� : "; for (int j = 0; j < cnt-1; j++) cout << arr[j];
        
    }
    return 0;
}
