#include <stdio.h>

int sqrtBinary(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;
        }
        else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int result = sqrtBinary(n);
    printf("%d", result);

    return 0;
}