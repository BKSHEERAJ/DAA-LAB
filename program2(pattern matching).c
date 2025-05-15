#include <stdio.h>
#include <string.h>

void patternMatch(char string[], char pattern[]) {
    int n = strlen(string);
    int m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (string[i + j] != pattern[j])
                break;
        }
        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char string[] = "this is a simple example";
    char pattern[] = "simple";
    patternMatch(string, pattern);
    return 0;
}
