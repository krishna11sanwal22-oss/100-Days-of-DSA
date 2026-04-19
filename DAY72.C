#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int freq[26] = {0};

    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';

        if (freq[index] == 1) {
            printf("%c", s[i]);
            return 0;
        }

        freq[index] = 1;
    }

    printf("-1");
    return 0;
}