#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct graph_node
{
    int number;
    struct graph_node *next;
} node;

node *insert(node *y, int number)
{
    node *x;
    x = (node *)malloc(sizeof(node));
    x->number = number;
    x->next = y;
    y = x;
    return y;
}

void dfs(node *arr[], int arrs[],int i)
{
    node *x;
    x = arr[i];
    while(x != NULL)
    {
        if (arrs[x->number - 1] == 0)
        {
            arrs[x->number - 1] = 1;
            dfs(arr,arrs,x->number - 1);
        }
        x = x->next;
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    node *arr[N];
    node *arr1[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = NULL;
        arr1[i] = NULL;
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[x - 1] = insert(arr[x - 1], y);
        arr1[y - 1] = insert(arr1[y - 1], x);
    }
    int arrs[N];
    int arrs1[N];
    memset(arrs,0,N*sizeof(int));
    memset(arrs1,0,N*sizeof(int));
    dfs(arr,arrs,0);
    dfs(arr1,arrs1,0);

    for (int i = 0;i<N;i++)
    {
        if (arrs[i] == 0 || arrs1[i] == 0)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}