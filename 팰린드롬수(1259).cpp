#include <stdio.h>
#include <string.h>

int palin(char str[]) {
	int left = 0, right = strlen(str) - 1;
	while (left < right)
		if (str[left++] != str[right--])return 0;
	return 1;
}
int main() {
	char str[6];
	while (1) {
		scanf("%s", &str);
		if (str[0] == '0')break;;
		if (palin(str))printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
}