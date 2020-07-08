/*

Solution for Exercise 2:

Write a program which can read an n × m matrix of integers
from stdin with the following format:

n = 2
m = 4
4 812 94 24
42 43 31 5

- use dynamic memory allocation to store the matrix in
memory

- output the largest and smallest value in each column of
the matrix

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void* safe_malloc(size_t bytes)
{
    void* ptr = malloc(bytes);
    if (ptr == NULL) {
        printf("error mallocing %lu bytes\n", bytes);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main(int argc, char const* argv[])
{
    uint32_t n, m;
    // (1) read dimensions
    // n == number of rows
    // m == number of cols
    if (scanf("n = %u\n", &n) != 1) {
        printf("error reading n dimension.\n");
        exit(EXIT_FAILURE);
    }
    if (scanf("m = %u\n", &m) != 1) {
        printf("error reading m dimension.\n");
        exit(EXIT_FAILURE);
    }

    // (2) allocate memory
    int32_t** matrix = (int32_t**)safe_malloc(n * sizeof(int32_t*));
    for (uint32_t i = 0; i < n; i++) {
        matrix[i] = (int32_t*)safe_malloc(m * sizeof(int32_t));
    }

    // (3) read the data
    for (uint32_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (scanf("%d", &(matrix[i][j])) != 1) {
                printf("error reading matrix data.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    // (4) compute stats
    for (uint32_t i = 0; i < m; i++) {
        int32_t min = INT32_MAX;
        int32_t max = INT32_MIN;
        for (size_t j = 0; j < n; j++) {
            min = MIN(min, matrix[j][i]);
            max = MAX(max, matrix[j][i]);
        }
        printf("col %8u: min = %8d max = %8d\n", i, min, max);
    }

    // (5) cleanup
    for (uint32_t i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return EXIT_SUCCESS;
}