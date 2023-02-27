#include <bits/stdc++.h>
using namespace std;

// 1로 구성된 최솟값과 N의 몇배수인지 출력하는 코드이다.

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
        cout << "각 자릿수가 모두 1로 이루어진 가장 작은 수는 " << string(ret, '1') << "이며, " << "\n";
        cout << "배수는 : "; for (int j = 0; j < ret-1; j++) cout << arr[j];
        
    }
    return 0;
}
