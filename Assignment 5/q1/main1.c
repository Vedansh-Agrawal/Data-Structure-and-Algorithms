#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct graph_node
{
    int number;
    struct graph_node* next; 
}node;



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
    int n,m,ans;
    scanf("%d %d",&n,&m);

    node * arr[m][n];
    for (int i = 0;i<m;i++)
    {
        for (int j = 0;j<n;j++)
        {
            arr[i][j] = NULL;
        }
    }

    for (int i = 0;i<m;i++)
    {
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        arr[c - 1][x - 1] = insert(arr[c - 1][x - 1],y);
        arr[c - 1][y - 1] = insert(arr[c - 1][y - 1],x);
    }

    int q;
    scanf("%d",&q);
    for (int i = 0;i<q;i++)
    {
        int x,y,ans = 0;
        scanf("%d %d",&x,&y);

       for (int i = 0;i<m;i++)
       {
           int arrs[n];
           memset(arrs,0,n*sizeof(int));
           dfs(arr[i],arrs,x - 1);
           if(arrs[y - 1] == 1)
           {
               ans++;
           }
       }

       printf("%d\n",ans);
    }

    return 0;
}