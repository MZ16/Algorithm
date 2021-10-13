#include <stdio.h>

int main() {
	int arr[9];
	int over, total = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		total += arr[i];
	}
	
	over = total - 100; 

	int a, b;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == over) {
				a = arr[i];
				b = arr[j];
				break;
			}
		}
	}

	int arr2[7];
	int cnt = 0;
	for (int i = 0; i < 9; i++) {
		if (arr[i] == a || arr[i] == b)continue;
		else arr2[cnt++] = arr[i];
	}
	
	
	for (int i = 0; i < 7; i++) {
		for (int j = i+1; j < 7; j++) {
			if (arr2[i] > arr2[j]) {
				int tmp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = tmp;
			}
		}
	}
	
	for (int i = 0; i < 7; i++) printf("%d\n", arr2[i]);
	
}

// 9명중 7명(100)을 뽑아야하니 total - 100을 통해 제외되는 난쟁이 2명을 구하면 됨