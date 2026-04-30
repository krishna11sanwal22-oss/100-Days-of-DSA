#include <stdio.h>

// Find max element
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Find sum of array
int findSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages)
            return 0;

        if(pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];

            if(students > m)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = findMax(arr, n);
    int high = findSum(arr, n);
    int result = high;

    // Binary Search
    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;  // Try smaller
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", result);

    return 0;
}


