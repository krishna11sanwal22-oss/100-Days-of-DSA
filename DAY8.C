#include <stdio.h>

int power(int a, int b)
{
    if(b == 0)
        return 1;
    else
        return a * power(a, b - 1);
}

int main()
{
    int a, b, result;

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    result = power(a, b);

    printf("Result = %d", result);

    return 0;
}