//Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main()
{
    int n, i, k;
    int arr[100];
    int comparisons = 0;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        comparisons++; 

        if(arr[i] == k)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Element not found\n");
    }

    printf("Total comparisons = %d\n", comparisons);

    return 0;
}