#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <vector>
using namespace std;
vector<pair<int, int>> stk;


void ConvExp(char exp[], char exp2[]) {
	int len = strlen(exp);
	int tok,cnt=0;
	int pop1, pop2;

	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (tok >= 65 && tok <= 90) { // �ǿ����ڶ�� push
			stk.push_back(make_pair(exp2[cnt++],tok)); // ���ÿ� int������ �ֱ�����
		}
		else{ // �����ڶ�� pop2��, ����, push
			pop2 = Lpop(&stk);
			pop1 = Lpop(&stk);			
			switch (tok)
			{
			case '*':
				Lpush(&stk, pop1 * pop2);
				break;
			case '/':
				Lpush(&stk, pop1 / pop2);
				break;
			case '+':
				Lpush(&stk, pop1 + pop2);
				break;
			case '-':
				Lpush(&stk, pop1 - pop2);
				break;
			}
		}
	}
	printf("%d\n", Lpop(&stk));

}


int main() {
	int TC,val;
	char exp[100];
	char exp2[100];
	scanf("%d", &TC);
	scanf("%s", exp);
	for (int i = 0; i < TC; i++) {
		scanf("%d", val);
		exp2[i] = val;
	}

	ConvExp(exp);
}