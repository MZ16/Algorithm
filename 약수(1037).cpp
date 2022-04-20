#include <stdio.h>
#include <stdlib.h>



int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
    int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ
    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ
    return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int main() {
	int TC,ans;	
	scanf("%d", &TC);
	int* arr = (int*)malloc(sizeof(int) * TC);
	
	for (int i = 0; i < TC; i++) scanf("%d", &arr[i]); 
	qsort(arr, TC, sizeof(int), compare);
	printf("%d", arr[0] * arr[TC-1]);
	return 0;
}