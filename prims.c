#include <stdio.h>

void prims(int n, int cost[50][50], int source)
{
    int i, j, k, u, v, min, d[50], N[50], t[20][3], s[50], sum;
    for (i = 1; i <= n; i++)
    {
        s[i] = 0;
        d[i] = cost[source][i];
        N[i] = source;
    }
    s[source] = 1;
    sum = 0;
    k = 1;
    for (i = 1; i < n; i++)
    {
        min = 999;
        u = 0;
        for (j = 1; j <= n; j++)
        {
            if (s[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        t[k][1] = u;
        t[k][2] = N[u];
        k++;
        sum = sum + cost[u][N[u]];
        s[u] = 1;
        for (v = 1; v <= n; v++)
        {
            if (s[v] == 0 && cost[u][v] < d[v])
            {
                d[v] = cost[u][v];
                N[v] = u;
            }
        }
    }
    if (sum > 999)
    {
        printf("no spanning tree is found");
    }
    else
    {
        printf("spanning tree is: ");
        for (i = 1; i < k; i++)
        {
            printf("%d->%d\n", t[i][1], t[i][2]);
        }
        printf("cost of spanning tree is: %d", sum);
    }
}

void main()
{
    int i, j, cost[50][50], source, n, min;
    source = 1;
    min = 999;
    printf("enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[i][j] != 0 && cost[i][j] < min)
            {
                min = cost[i][j];
                source = i;
            }
        }
    }
    printf("source node is %d \n", source);
    prims(n, cost, source);
}