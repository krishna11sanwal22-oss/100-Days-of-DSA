#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int start = 0, end, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    end = strlen(str) - 1;

    while(start < end)
    {
        if(str[start] != str[end])
        {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    if(flag == 1)
        printf("The string is a Palindrome");
    else
        printf("The string is NOT a Palindrome");

    return 0;
}