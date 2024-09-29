#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k, int n)
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int n, x[20], k, count = 0, i;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    k = 1;
    x[k] = 0;
    while (k != 0)
    {
        x[k] = x[k] + 1;
        while (x[k] <= n && !place(x, k, n))
        {
            x[k] = x[k] + 1;
        }
        if (x[k] <= n)
        {
            if (k == n)
            {
                count++;
                printf("Solution %d: ", count);
                for (i = 1; i <= n; i++)
                {
                    printf("%d ", x[i]);
                }
                printf("\n");
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
    if (count == 0)
    {
        printf("No solution exists");
    }
}