#include <stdio.h>

int main() {
    int n, i, j, k, l;

    printf("Enter the number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (k = 0; k < i; k++) {
            printf("*");
        }
        for (l = 0; l < k - 1; l++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (k = 0; k < i; k++) {
            printf("*");
        }
        for (l = 0; l < k - 1; l++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
