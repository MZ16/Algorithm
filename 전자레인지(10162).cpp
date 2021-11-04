#include <stdio.h>

int main()
{
    int T, A = 0, B = 0, C = 0;
    scanf("%d", &T);
    if (T % 10) printf("-1");
    else
    {
        A = T / 300;
        T %= 300;
        B = T / 60;
        T %= 60;
        C = T / 10;
        T %= 10;
        printf("%d %d %d", A, B, C);
    }

    return 0;
}
