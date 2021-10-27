#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[9],chk1=0,chk2=0;
	for (int i = 0; i < 8; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 7; i++) {
		if (arr[i] + 1 == arr[i + 1])chk1 = 1;
		else {
			chk1 = 0;
			break;
		}
	}

	for (int i = 0; i < 7; i++) {
		if (arr[i] - 1 == arr[i + 1]) chk2 = 1;
		else {
			chk2 = 0;
			break;
		}
	}

	if (chk1 == 1)printf("ascending");
	else if(chk2==1)printf("descending");
	else printf("mixed");
}
