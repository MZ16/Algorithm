#include <stdio.h>
#include <string.h>

int main() {
	int TC;
	scanf("%d", &TC);
	char str[81];
	int cnt = 0,sum=0;

	for (int i = 0; i < TC; i++) {
		memset(str, 0, sizeof(str) / sizeof(char));
		scanf("%s", &str);
		
		for (int j = 0; str[j] != '\0'; j++) {
			if (str[j] == 'O') {
				++cnt;
				sum += cnt;
				//printf("cnt:%d sum:%d \n", cnt, sum);
			}
			if (str[j] == 'X') {
				cnt = 0;
			}
		}
		printf("%d\n", sum);
		sum = 0;
		cnt = 0;
		
	}
}