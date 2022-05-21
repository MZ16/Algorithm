#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 중간 평균값 구하기. 1984
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int max = 0, min = 987654321;
		int arr[10];
		int sum = 0; double ans;
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
			sum += arr[i];
			max = arr[i] > max ? arr[i] : max;
			min = arr[i] > min ? min : arr[i];			
		}
		ans = (sum - (max + min));
		printf("#%d %d\n", i, (int)(ans/8+0.5));
	}


	return 0;
}