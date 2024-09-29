#include <stdio.h>

void djikstra(int n, int cost[20][20], int source, int dest, int s[20], int d[20], int p[20])
{
    int i, j, u, v, min;
    s[source] = 1;
    for (i = 1; i < n; i++)
    {
        min = 999;
        u = 0;
        for (j = 1; j <= n; j++)
        {
            if (s[j] == 0 && d[j] <= min)
            {
                min = d[j];
                u = j;
            }
        }
        s[u] = 1;
        for (v = 1; v <= n; v++)
        {
            if (s[v] == 0 && d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
    }
}
void printpath(int source, int dest, int d[20], int p[20])
{
    int i;
    if (d[dest] == 999)
    {
        printf("No Path");
    }
    i = dest;
    while (i != source)
    {
        printf("%d<-", i);
        i = p[i];
    }
    printf("%d=%d \n", source, d[dest]);
}

void main()
{
    int n, i, j, cost[20][20], s[20], d[20], p[20], source, dest;
    printf("enter number of vertices");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("enter the source: ");
    scanf("%d", &source);
    for (i = 1; i <= n; i++)
    {
        s[i] = 0;
        d[i] = cost[source][i];
        p[i] = source;
    }
    djikstra(n, cost, source, dest, s, d, p);
    printf("shortest path is: ");
    for (dest = 1; dest <= n; dest++)
    {
        if (dest != source)
        {
            printpath(source, dest, d, p);
        }
    }
}