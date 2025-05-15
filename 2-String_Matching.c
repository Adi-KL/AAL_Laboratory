#include <stdio.h>
#include <string.h>

void bruteForceMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j, found = 0;

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}


int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search: ");
    scanf("%s", pattern);
    bruteForceMatch(text, pattern);
   return 0;
}
