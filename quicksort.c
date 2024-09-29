#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[1000], int low, int high)
{
    int i, j, key, temp;
    i = low + 1;
    key = a[low];
    j = high;
    while (i <= j)
    {
        while (i <= high && key <= a[i])
        {
            i++;
        }
        while (j >= low && key > a[j])
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[1000], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

void main()
{
    int i, a[1000], n;
    float time_taken;
    clock_t start, end;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();
    time_taken = (float)(end - start) / CLOCKS_PER_SEC;
    printf("sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("time take is %f", time_taken);
}