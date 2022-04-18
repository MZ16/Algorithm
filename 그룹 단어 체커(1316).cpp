#include <stdio.h>
#include <string.h>

/*
* 1. 이전 단어와 같을경우 (연속)
* 2. 이미 나왔던 단어이며 앞의 단어와 다를경우 (그룹 단어가 아님)
* 3. 이전 단어와 다르지만 나오지 않은 경우
*/
int main() {
	int TC,cnt=0;
	char word[101];
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%s", word);
		bool alphabet[26] = { false, };
		alphabet[word[0] - 97] = true;
		for (int j = 1; word[j] != '\0'; j++) {
			if (word[j] == word[j - 1])continue;
			else if (alphabet[word[j] - 'a'] == true &&
				word[j] != word[j - 1]) {
				cnt++;
				break;
			}
			else {
				alphabet[word[j] - 'a'] = true;
			}
		}
		

	}
	printf("%d", TC - cnt);
	return 0;
}