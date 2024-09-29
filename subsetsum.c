#include <stdio.h>
void subset(int n, int a[20], int d)
{
    int i, j, x[50], sum, count, k;
    for (i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
    sum = 0;
    count = 0;
    k = 1;
    x[k] = 1;
    while (1)
    {
        if (k <= n)
        {
            if (sum + a[k] == d)
            {
                count++;
                printf("subset %d is: ", count);
                for (i = 1; i <= k; i++)
                {
                    if (x[i] == 1)
                    {
                        printf("%d ", a[i]);
                    }
                }
                printf("\n");
                x[k] = 0;
                k = k + 1;
                x[k] = 1;
            }
            else if (sum + a[k] < d)
            {
                sum = sum + a[k];
                k = k + 1;
                x[k] = 1;
            }
            else
            {
                x[k] = 0;
                k = k + 1;
                x[k] = 1;
            }
        }
        else
        {
            x[k] = 0;
            k = k - 1;
            while (k != 0 && x[k] == 0)
            {
                k = k - 1;
            }
            if (k == 0)
            {
                return;
            }
            x[k] = 0;
            sum = sum - a[k];
            k = k + 1;
            x[k] = 1;
        }
    }
    if (count == 0)
    {
        printf("no subset found\n");
    }
}

void main()
{
    int n, a[20], d, i;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    printf("enter the elements: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the sum: ");
    scanf("%d", &d);
    subset(n, a, d);
}