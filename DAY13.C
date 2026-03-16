#include <stdio.h>

int main() {
    int r, c, i;
    
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    printf("Spiral Order Traversal:\n");

    while(top <= bottom && left <= right) {

        // Top row
        for(i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Right column
        for(i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Bottom row
        if(top <= bottom) {
            for(i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Left column
        if(left <= right) {
            for(i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}