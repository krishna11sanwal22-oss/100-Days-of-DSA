#include <stdio.h>

int main() {
    int n, k, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n; // handle k > n

    int temp[k];

    // Store last k elements
    for(i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift remaining elements
    for(i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy temp to front
    for(i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    // Print result
    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}