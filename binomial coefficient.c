#include <stdio.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int n = 6, k = 4;
    long long c = factorial(n) / (factorial(k) * factorial(n - k));
    printf("C(%d, %d) = %lld\n", n, k, c);
    return 0;
}
