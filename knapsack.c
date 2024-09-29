#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int n, int m, int w[20], int p[20], int v[20][20])
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (w[i - 1] > j)
            {
                v[i][j] = v[i - 1][j];
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i - 1]] + p[i - 1]);
            }
        }
    }
}

// Function to print the solution
void print(int n, int m, int w[20], int p[20], int v[20][20])
{
    int i, j, x[20];
    printf("optimal solution is %d\n", v[n][m]);

    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    i = n;
    j = m;

    while (i > 0 && j > 0)
    {
        if (v[i][j] != v[i - 1][j])
        {
            x[i - 1] = 1;
            j = j - w[i - 1];
        }
        i = i - 1;
    }

    printf("objects included are\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %d\n", i + 1, x[i]);
    }
}

// Main function
int main()
{
    int i, j, n, m, w[20], p[20], v[20][20];

    // Input
    printf("enter the number of objects\n");
    scanf("%d", &n);

    printf("enter the weights of the objects\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    printf("enter the profits of the objects\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("enter the capacity of knapsack\n");
    scanf("%d", &m);

    knapsack(n, m, w, p, v);

    printf("the knapsack matrix is\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    print(n, m, w, p, v);

    return 0;
}
