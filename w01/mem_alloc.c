//gcc -Wall -std=c99 WS1 helloworld.c -o ex -lm -g


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    double total_time;
    clock_t start, end;
    start = clock();

    // Program starts here

    int *arr;
    int limit, i;
    int sum = 0;

    printf("Enter total number of array elements: ");
    scanf("%d", &limit);

    arr = (int*)malloc(limit*sizeof(int));
    if(arr == NULL)
    {
        printf("Insufficient Memory");
        return 0;
    }


    printf("Enter %d elements: \n", limit);
    for(i = 0;i<limit; i++)
    {
        printf("Enter element %3d: ", i + 1);
        scanf("%d", (arr + i));
        sum = sum + *(arr + i);
    }

    printf("Array elements are: ");
    for(i=0; i<limit; i++)
    {
        printf("%3d ", *(arr + i));

    }
    printf("\nSum of all elements: %d\n", sum);
    
    free(arr);
    

    // Finishes here

    end = clock();
	total_time = ((double) (end - start)) / CLK_TCK;
	printf("\nTime taken is: %f", total_time);
    return 0;
}