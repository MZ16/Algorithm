#include <stdio.h>
int arr[10050];

int n(int data) {
	int val = data;
	if (data >= 10000) { val += data / 10000; data %= 10000; }
	if (data >= 1000) { val += data / 1000; data %= 1000; }
	if (data >= 100) { val += data / 100; data %= 100; }
	if (data >= 10) { val += data / 10; data %= 10; }
	return val += data;
}

int main() {
	for (int i = 1; i < 10001; i++) {
		arr[n(i)] = 1;
		if (arr[i] != 1)printf("%d\n",i);
	}
}