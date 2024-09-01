#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct tree
{
    int number;
    struct tree *left;
    struct tree *right;
} node;

int sums(node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    int sum = tree->number;
    sum += sums(tree->left);
    sum += sums(tree->right);
    return sum;
}

node *createnode(int A)
{
    node *temp = malloc(sizeof(node));
    temp->number = A;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
}

node *createtree(int n, int arr[])
{
    node *tree;
    node *temp1 = createnode(arr[0]);
    tree = temp1;
    node *point[2 * n];

    point[0] = tree;

    int i = 1, x = 0, y = 1;

    while (i < n)
    {
        if (arr[i] == 0)
        {
            point[x]->left = NULL;
            i += 1;
        }
        else
        {
            node *temp = createnode(arr[i]);
            point[x]->left = temp;
            i++;
            point[y] = point[x]->left;
            y++;
        }
        if (i >= n)
        {
            x++;
            break;
        }

        if (arr[i] == 0)
        {
            point[x]->right = NULL;
            i++;
        }
        else
        {
            node *temp = createnode(arr[i]);
            point[x]->right = temp;
            i++;
            point[y] = point[x]->right;
            y++;
        }
        x++;
    }

    for (int j = x; j < y; j++)
    {
        point[j]->left = NULL;
        point[j]->right = NULL;
    }

    return tree;
}


void Delete(node **tree)
{
    if (*tree == NULL)
    {
        return;
    }

    node *ptr = *tree;
    Delete(&ptr->left);
    ptr->left = NULL;
    Delete(&ptr->right);
    ptr->right = NULL;
    free(ptr);
    *tree = NULL;
}

int increase(int max, int min, node *tree)
{
    if (tree == NULL)
    {
        return 1;
    }

    if (tree->number >= min && tree->number <= max)
    {
        if (!increase(tree->number-1,min,tree->left))
        {
            return 0;
        }
        if (!increase(max,tree->number+1,tree->right))
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

int decrease(int max, int min, node *tree)
{
    if(tree == NULL)
    {
        return 1;
    }

    if (tree->number >= min && tree->number <= max)
    {
        if (!decrease(max, tree->number+1,tree->left))
        {
            return 0;
        }

        if (!decrease(tree->number-1,min,tree->right))
        {
            return 0;
        }
        return 1;
    }

    return 0;
}

void inorder(int *max,int *min,int *minimumsum,node *tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (decrease(*max,*min,tree) == 1)
    {
        int sum = sums(tree);
        if (sum < *minimumsum)
        {
            *minimumsum = sum;
        }
    }

    else if (increase(*max,*min,tree) == 1)
    {
        int sum = sums(tree);
        if (sum < *minimumsum)
        {
            *minimumsum = sum;
        }
    }

    inorder(max,min,minimumsum,tree->left);
    inorder(max,min,minimumsum,tree->right);

    return;

}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int min = -1e9,max = 1e9,minimumsum = 1e9;

        node *tree = createtree(n, arr);
        inorder(&max,&min,&minimumsum,tree);
        printf("%d\n",minimumsum);

        Delete(&tree);
        assert(tree == NULL);
    }
    return 0;
}