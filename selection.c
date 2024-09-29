#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void selection(int n, int a[10000])
{
    int i, j, temp, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

void main()
{
    int i, n, a[10000];
    float time_taken;
    clock_t start, end;
    printf("enter size of the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    printf("array before sorting");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    start = clock();
    selection(n, a);
    end = clock();
    time_taken = (float)(end - start) / CLOCKS_PER_SEC;
    printf("elements after sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("total time taken is: %f", time_taken);
}