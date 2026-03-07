//A system receives two separate logs of user arrival times from two different servers.
// Each log is already sorted in ascending order. Your task is to create a single chronological 
//log that preserves the correct order of arrival
#include <stdio.h>

int main()
{
    int a[50], b[50], c[100];
    int n1, n2, i, j, k;

    printf("Enter number of elements in first log: ");
    scanf("%d", &n1);

    printf("Enter elements of first log (sorted):\n");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter number of elements in second log: ");
    scanf("%d", &n2);

    printf("Enter elements of second log (sorted):\n");
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Merged chronological log:\n");
    for(i = 0; i < n1 + n2; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}