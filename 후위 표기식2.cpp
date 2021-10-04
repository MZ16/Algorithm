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
		if (tok >= 65 && tok <= 90) { // 피연산자라면 push
			stk.push_back(make_pair(exp2[cnt++],tok)); // 스택에 int형으로 넣기위함
		}
		else{ // 연산자라면 pop2번, 연산, push
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