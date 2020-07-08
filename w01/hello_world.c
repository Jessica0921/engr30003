//gcc -Wall -std=c99 WS1 helloworld.c -o ex -lm -g


#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) 
{
    double total_time;
    clock_t start, end;
    start = clock();

    // Program starts here

    printf("Hello World!");

    // Finishes here

    end = clock();
	total_time = ((double) (end - start)) / CLK_TCK;
	printf("\nTime taken is: %f", total_time);
    return 0;
}