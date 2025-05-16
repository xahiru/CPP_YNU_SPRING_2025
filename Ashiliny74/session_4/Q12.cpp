#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    // Dynamically allocate memory for array
    int* squares = (int*)malloc(n * sizeof(int));
    if (squares == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Calculate squares
    for (int i = 1; i <= n; i++) {
        squares[i - 1] = i * i; // Store square of i
    }

    // Print squares
    printf("Squares: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", squares[i]);
    }
    printf("\n");

    // Free allocated memory
    free(squares);
    return 0;
}