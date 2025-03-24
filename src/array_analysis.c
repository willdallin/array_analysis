#include "array_analysis.h"
#include <stdio.h>
#include <stdlib.h>

ArrayStats analyze_array(const int *input, size_t n) {
    ArrayStats result = {0};

    if (input == NULL || n == 0) {
        fprintf(stderr, "Error: Invalid array or zero length.\n");
        return result;
    }

    int sum = 0;
    int max = input[0];
    int min = input[0];
    size_t even_index = 0;

    int *temp_even = (int *)malloc(n * sizeof(int));
    if (temp_even == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return result;
    }

    for (size_t i = 0; i < n; i++) {
        int val = input[i];
        sum += val;
        if (val > max) max = val;
        if (val < min) min = val;
        if (val % 2 == 0) {
            temp_even[even_index++] = val;
        }
    }

    result.max = max;
    result.min = min;
    result.average = (float)sum / n;
    result.even_size = even_index;

    if (even_index > 0) {
        int *even_array = (int *)realloc(temp_even, even_index * sizeof(int));
        if (even_array == NULL) {
            result.even_array = temp_even;
        } else {
            result.even_array = even_array;
        }
    } else {
        free(temp_even);
        result.even_array = NULL;
    }

    return result;
}

void free_array_stats(ArrayStats *stats) {
    if (stats->even_array != NULL) {
        free(stats->even_array);
        stats->even_array = NULL;
        stats->even_size = 0;
    }
}
