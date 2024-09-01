#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct graph_node
{
    int number;
    int colour;
    struct graph_node* next; 
}node;

void searchcolour(node *d,node *arr[], int colour, int y[], int z[], int *i)
{
    node *x;
    x = arr[d->number - 1];
    
    while (x != NULL)
    {
        if (x->colour == colour && y[x->number - 1] == 0)
        {
            z[*i] = x->number;
            *i += 1;
            y[x->number - 1] = 1;
            searchcolour(x,arr,colour,y,z,i);
        }
        x = x->next;
    }
}

int search(node *arr[], int x, int y, int m, int n)
{
    int a[m], ans = 0;
    memset(a, 0, m * sizeof(int));
    node *b;
    b = arr[x - 1];

    while (b != NULL)
    {
        int colour = b->colour;
        int c[n];
        memset(c, 0, n * sizeof(int));

        c[x - 1] = 1;
        c[b->number - 1] = 1;
        node *d = b;

        if (b->number == y)
        {
            a[colour - 1] = 1;
            do
            {
                b = b->next;
            } while (b != NULL && a[b->colour - 1] == 1);
            continue;
        }

        int z[m];
        memset(z,0,n*sizeof(int));
        int i;
        i = 0;
        searchcolour(d,arr,colour,c,z,&i);

        for (int i = 0;i<m;i++)
        {
            if (z[i] == y)
            {
                a[colour - 1] = 1;
                break;
            }
        }

        do
        {
            b = b->next;
        } while (b != NULL && a[b->colour - 1] == 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i] == 1)
        {
            ans++;
        }
    }

    return ans;
}

node *insert(node *y, int number, int colour)
{
    node *x;
    x = (node *)malloc(sizeof(node));
    x->number = number;
    x->colour = colour;
    x->next = y;
    y = x;
    return y;
}


int main()
{
    int n,m,ans;
    scanf("%d %d",&n,&m);

    node * arr[n];
    for (int i = 0;i<n;i++)
    {
        arr[i] = NULL;
    }

    for (int i = 0;i<m;i++)
    {
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        arr[x - 1] = insert(arr[x - 1],y,c);
        arr[y - 1] = insert(arr[y - 1],x,c);
    }

    int q;
    scanf("%d",&q);
    for (int i = 0;i<q;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        ans = search(arr,x,y,n,m);
        printf("%d\n",ans);
    }

    return 0;
}