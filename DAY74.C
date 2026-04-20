#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];
    for (int i = 0; i < n; i++)
        scanf("%s", names[i]);

    char unique[n][50];
    int count[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1)
            count[found]++;
        else {
            strcpy(unique[size], names[i]);
            count[size] = 1;
            size++;
        }
    }

    int max = count[0];
    char winner[50];
    strcpy(winner, unique[0]);

    for (int i = 1; i < size; i++) {
        if (count[i] > max) {
            max = count[i];
            strcpy(winner, unique[i]);
        } else if (count[i] == max) {
            if (strcmp(unique[i], winner) < 0)
                strcpy(winner, unique[i]);
        }
    }

    printf("%s %d", winner, max);

    return 0;
}