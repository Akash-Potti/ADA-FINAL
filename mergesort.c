#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void simplemerge(int a[1000], int low, int mid, int high)
{
    int i, j, k, temp[1000];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (i = 0; i < high; i++)
    {
        a[i] = temp[i];
    }
}

void mergesort(int a[1000], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        simplemerge(a, low, mid, high);
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
    mergesort(a, 0, n - 1);
    end = clock();
    time_taken = (float)(end - start) / CLOCKS_PER_SEC;
    printf("sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("time take is %f", time_taken);
}