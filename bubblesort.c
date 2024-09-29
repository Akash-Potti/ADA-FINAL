#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int a[10000], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int i, j, a[10000], n;
    float time_taken;
    clock_t start,
        end;
    printf("enter size of array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    printf("elements of array are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    start = clock();
    bubblesort(a, n);
    end = clock();
    time_taken = (float)(end - start) / CLOCKS_PER_SEC;
    printf("sorted elements are: ");
    for (j = 0; j < n; j++)
    {
        printf("%d", a[j]);
    }
    printf("total time taken is: %f", time_taken);
}