#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INIT_SIZE 5

// data type

typedef struct {
    int r;
    int g;
    int b;
    
} data_t;

// Function that inserts r,g,b into a data struct
data_t new_rgb(int r, int g, int b)
{
    data_t d;
    d.r = r;
    d.g = g;
    d.b = b;
    return d;
}

/* stack type */
typedef struct {
    int array_size;
    data_t* array;
    int top;
} stack_t;