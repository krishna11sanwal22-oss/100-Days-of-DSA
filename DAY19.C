#include <stdio.h>
#include <stdlib.h>

// Function to compare for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = 1000000;
    int x, y;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            x = arr[left];
            y = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("Pair closest to zero: %d and %d\n", x, y);
    printf("Sum = %d\n", min_sum);

    return 0;
}