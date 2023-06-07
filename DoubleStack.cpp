#include<stdio.h>
#define MAX 5

/*
* Array에서 두 개의 스택을 유지 관리할 수 있습니다.
  이러한 유형의 구현을 이중 스택이라고 합니다.
  이 구현에서는 두 스택이 서로 반대 방향으로 증가합니다.
  하나는 하위 인덱스에서 상위 인덱스로, 
  두 번째는 상위 인덱스에서 하위 인덱스로.
*/

//Declaration of Double Stack
typedef struct
{
    int top1;
    int top2;
    int ele[MAX];
}DStack;

//Initialization of Double Stack
void init(DStack* s)
{
    s->top1 = -1;
    s->top2 = MAX;
}

//Push Operation on Stack1
void pushA(DStack* s, int item)
{
    if (s->top2 == s->top1 + 1)
    {
        printf("\nStack Overflow Stack1");
        return;
    }

    s->top1++;
    s->ele[s->top1] = item;

    printf("\nInserted item in Stack1 : %d", item);
}

//Push Operation on Stack2
void pushB(DStack* s, int item)
{
    if (s->top2 == s->top1 + 1)
    {
        printf("\nStack Overflow Stack2");
        return;
    }

    s->top2--;
    s->ele[s->top2] = item;

    printf("\nInserted item in Stack2 : %d", item);
}

//Pop Operation on Stack1
int popA(DStack* s, int* item)
{
    if (s->top1 == -1)
    {
        printf("\nStack Underflow Stack1");
        return -1;
    }

    *item = s->ele[s->top1--];
    return 0;
}

//Pop Operation on Stack2
int popB(DStack* s, int* item)
{
    if (s->top2 == MAX)
    {
        printf("\nStack Underflow Stack2");
        return -1;
    }

    *item = s->ele[s->top2++];
    return 0;
}


int main()
{
    int item = 0;

    DStack s;

    init(&s);

    pushA(&s, 10);
    pushA(&s, 20);
    pushA(&s, 30);
    pushB(&s, 40);
    pushB(&s, 50);
    pushB(&s, 60);


    if (popA(&s, &item) == 0)
        printf("\nDeleted item From Stack1 : %d", item);
    if (popA(&s, &item) == 0)
        printf("\nDeleted item From Stack1 : %d", item);
    if (popA(&s, &item) == 0)
        printf("\nDeleted item From Stack1 : %d", item);
    if (popB(&s, &item) == 0)
        printf("\nDeleted item From Stack2 : %d", item);
    if (popB(&s, &item) == 0)
        printf("\nDeleted item From Stack2 : %d", item);
    if (popB(&s, &item) == 0)
        printf("\nDeleted item From Stack2 : %d", item);

    printf("\n");
    return 0;
}