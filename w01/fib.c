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

    int num_1 = 0;
    int num_2 = 1;
    int temp;

    printf("%d\n%d\n", num_1, num_2);    

    int i = 0;
    for(i = 0; i<10; i++)
    {
        temp = num_2;
        num_2 = num_1 + num_2;
        num_1 = temp;
        printf("%d\n", num_2);

    }

    // Finishes here

    end = clock();
	total_time = ((double) (end - start)) / CLK_TCK;
	printf("\nTime taken is: %f", total_time);
    return 0;
}