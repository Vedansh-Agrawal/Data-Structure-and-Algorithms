#include <stdio.h>
#include <stdlib.h>



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

void dist(int x, int k, int M[][k],node *arr[],int *ans,int p)
{
    node *a;

    M[x][0] = 1;
    for(a = arr[x - 1]; a != NULL;a = a->next)
    {
        if(a->number != p)
        {
            dist(a->number,k,M,arr,ans,x);

            for(int i = 0;i<k;i++)
            {
                *ans += M[x][i] * M[a->number][k - i - 1];
            }

            for (int i = 0;i<k;i++)
            {
                M[x][i + 1] += M[a->number][i];
            }
        }
    }
}

int main()
{
    int q, ans = 0;
    scanf("%d", &q);

    for (int z = 0; z < q; z++)
    {
        ans=0;
        int N, k;
        
        scanf("%d %d", &N, &k);

        int M[N+1][k+1];


        for (int i = 0;i<N+1;i++)
        {
            for (int j = 0;j<k+1;j++)
            {
                M[i][j] = 0;
            }
        }

        node *arr[N];

        for (int i = 0; i < N; i++)
        {
            arr[i] = NULL;
        }

        for (int i = 0; i < N - 1; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x - 1] = insert(arr[x - 1], y);
            arr[y - 1] = insert(arr[y - 1], x);
        }

        if (k == 0)
        {
            printf("%d\n",N);
            continue;
        }

        dist(1,k,M,arr,&ans,0);
        printf("%d\n", ans);
    }

    return 0;
}