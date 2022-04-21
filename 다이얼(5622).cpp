#include <stdio.h>
//65~90

int main() {
	int arr[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10 };
	char str[16];
	int sum = 0;
	scanf("%s", &str);
	for (int i = 0; str[i] != '\0'; i++) sum += arr[str[i] - 'A'];
	printf("%d", sum);

	return 0;
}