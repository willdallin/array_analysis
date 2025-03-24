#ifndef ARRAY_ANALYSIS_H
#define ARRAY_ANALYSIS_H

#include <stddef.h>

typedef struct {
    float average;
    int max;
    int min;
    int *even_array;
    size_t even_size;
} ArrayStats;

ArrayStats analyze_array(const int *input, size_t n);
void free_array_stats(ArrayStats *stats);

#endif
