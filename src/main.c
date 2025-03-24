#include "array_analysis.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(const int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *input_array = NULL;
    size_t size = 0;

    printf("=== Array Analysis ===\n");
    printf("1. Manually enter the array values\n");
    printf("2. Automatically generate the array (random values)\n");
    printf("Choose an option (1 or 2): ");

    int option;
    scanf("%d", &option);

    if (option == 1) {
        printf("How many elements do you want to enter? ");
        scanf("%zu", &size);

        input_array = (int *)malloc(size * sizeof(int));
        if (!input_array) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }

        for (size_t i = 0; i < size; i++) {
            printf("Enter value %zu: ", i + 1);
            scanf("%d", &input_array[i]);
        }

    } else if (option == 2) {
        int min, max;
        printf("How many elements do you want to generate? ");
        scanf("%zu", &size);
        printf("Enter the minimum value: ");
        scanf("%d", &min);
        printf("Enter the maximum value: ");
        scanf("%d", &max);

        if (min > max) {
            printf("Error: Minimum value cannot be greater than maximum.\n");
            return 1;
        }

        input_array = (int *)malloc(size * sizeof(int));
        if (!input_array) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }

        srand(time(NULL));
        for (size_t i = 0; i < size; i++) {
            input_array[i] = rand() % (max - min + 1) + min;
        }

        printf("Generated array: ");
        print_array(input_array, size);
    } else {
        printf("Invalid option.\n");
        return 1;
    }

    // Analyze the array
    ArrayStats stats = analyze_array(input_array, size);

    printf("\n--- Results ---\n");
    printf("Average: %.2f\n", stats.average);
    printf("Maximum: %d\n", stats.max);
    printf("Minimum: %d\n", stats.min);
    printf("Even numbers (%zu): ", stats.even_size);
    for (size_t i = 0; i < stats.even_size; i++) {
        printf("%d ", stats.even_array[i]);
    }
    printf("\n");

    // Free memory
    free_array_stats(&stats);
    free(input_array);

    return 0;
}