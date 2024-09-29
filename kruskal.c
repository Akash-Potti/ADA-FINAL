#include <stdio.h>
struct edge
{
    int u;
    int v;
    int wt;
};
typedef struct edge EDGE;

int create_min_edge(int n, int cost[20][20], EDGE e[50])
{
    int i, j, min, k;
    k = 1;
    min = 999;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                e[k].u = i;
                e[k].v = j;
                e[k].wt = cost[i][j];
                k++;
            }
        }
    }
    return k - 1;
}
int min_edge(int n, EDGE e[50])
{
    int i, min, pos;
    min = 999;
    pos = -1;
    for (i = 1; i <= n; i++)
    {
        if (e[i].wt < min)
        {
            min = e[i].wt;
            pos = i;
        }
    }
    return pos;
}
int find(int p, int s[20])
{
    while (p != s[p])
    {
        p = s[p];
    }
    return p;
}

void unionij(int i, int j, int s[20])
{
    if (i < j)
    {
        s[j] = i;
    }
    else
    {
        s[i] = j;
    }
}

void kruskal(int n, int cost[20][20])
{
    int m, pos, i, j, k, u, v, sum, s[20], t[20][3], count, wt;
    EDGE e[50];
    for (i = 1; i <= n; i++)
    {
        s[i] = i;
    }
    m = create_min_edge(n, cost, e);
    k = 1;
    sum = 0;
    count = 0;

    while (count != n - 1)
    {
        pos = min_edge(m, e);
        if (pos == -1)
        {
            return;
        }
        u = e[pos].u;
        v = e[pos].v;
        wt = e[pos].wt;
        e[pos].wt = 999;
        i = find(u, s);
        j = find(v, s);
        if (i != j)
        {
            t[k][1] = u;
            t[k][2] = v;
            k++;
            count++;
            sum = sum + cost[u][v];
            unionij(i, j, s);
        }
    }
    if (count == n - 1)
    {
        printf("spanning tree is: \n");
        for (i = 1; i < n; i++)
        {
            printf("%d->%d\n", t[i][1], t[i][2]);
        }
        printf("cost of spanning tree is: %d", sum);
    }
    else
    {
        printf("no spanning tree.");
    }
}

void main()
{
    int n, i, j, cost[20][20];
    printf("enter number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    kruskal(n, cost);
}