#include <stdio.h>

int lowerBound(int a[], int n, int x)
{
    int low = 0, high = n - 1, ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(int a[], int n, int x)
{
    int low = 0, high = n - 1, ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, x;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);

    int lb = lowerBound(a, n, x);
    int ub = upperBound(a, n, x);

    printf("%d %d", lb, ub);

    return 0;
}