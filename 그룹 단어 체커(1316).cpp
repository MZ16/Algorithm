#include <stdio.h>
#include <string.h>

/*
* 1. ���� �ܾ�� ������� (����)
* 2. �̹� ���Դ� �ܾ��̸� ���� �ܾ�� �ٸ���� (�׷� �ܾ �ƴ�)
* 3. ���� �ܾ�� �ٸ����� ������ ���� ���
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