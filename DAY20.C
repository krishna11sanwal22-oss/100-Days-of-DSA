#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int countZeroSumSubarrays(int arr[], int n) {
    int prefix_sum = 0;
    int count = 0;

    
    int hash[2 * MAX + 1] = {0};

    
    int offset = MAX;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];


        if (prefix_sum == 0)
            count++;

        
        if (hash[prefix_sum + offset] > 0)
            count += hash[prefix_sum + offset];

    
        hash[prefix_sum + offset]++;
    }

    return count;
}

int main() {
    int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countZeroSumSubarrays(arr, n);
    printf("Number of zero-sum subarrays: %d\n", result);

    return 0;
}