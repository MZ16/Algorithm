#include <stdio.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

//버블정렬

void bubble(int a[], int n) {
	int i, j, tmp;

	for (i = n - 1; i > 0; i--) {

		for (j = 0; j < i; j++)
			if (a[j] > a[j + 1]) {
				swap(int, a[j], a[j + 1]);

				for (tmp = 0; tmp < 5; tmp++)
					printf("%d ", a[tmp]);

				putchar('\n');
			}
	}
}

int main(void) {
	int i;
	int n[5];

	for (i = 0; i < 5; i++)
		scanf("%d", &n[i]);

	bubble(n, 5);

	return 0;
}