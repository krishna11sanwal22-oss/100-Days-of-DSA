#include <stdio.h>

int main()
{
    int a[100], n, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    j = 0;

    for(i = 1; i < n; i++)
    {
        if(a[i] != a[j])
        {
            j++;
            a[j] = a[i];
        }
    }

    printf("Unique elements are:\n");
    for(i = 0; i <= j; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}