#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    long long int number;
    struct tree *left;
    struct tree *right;
    struct tree *up;
} node;

void addnode(node **root, long long int A, long long int B, long long int C, node *nodes[]);
node *createnode(long long int A);
void preorder(node *root, long long int *i, long long int arr1[], long long int *arra1[], char H[], char str[]);

node *createnode(long long int A)
{
    node *temp = malloc(sizeof(node));
    temp->number = A;
    temp->right = NULL;
    temp->left = NULL;
    temp->up = NULL;

    return temp;
}

void addnode(node **root, long long int A, long long int B, long long int C, node *nodes[])
{
    if (C == 1)
    {
        nodes[A - 1]->left = nodes[B - 1];
        nodes[B - 1]->up = nodes[A - 1];
    }

    else
    {
        nodes[A - 1]->right = nodes[B - 1];
        nodes[B - 1]->up = nodes[A - 1];
    }

    if (nodes[A - 1]->up == NULL)
        *root = nodes[A - 1];
}

void preorder(node *root, long long int *i, long long int arr1[], long long int *arra1[], char H[], char str[])
{
    if (root == NULL)
    {
        return;
    }
    *i += 1;
    arra1[root->number - 1] = &arr1[(*i) - 1];
    str[(*i) - 1] = H[root->number - 1];

    preorder(root->left, i, arr1, arra1, H, str);
    preorder(root->right, i, arr1, arra1, H, str);
}

int main()
{
    node *root;
    long long int N;
    scanf("%lld", &N);
    char H[N + 1];

    scanf("%s", H);

    node *nodes[N];

    for (long long int i = 1; i <= N; i++)
    {
        nodes[i - 1] = createnode(i);
    }

    for (long long int i = 0; i < N - 1; i++)
    {
        long long int A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);
        addnode(&root, A, B, C, nodes);
    }

    char S[1000000];
    scanf("%s", S);
    long long int Q, i = 0;
    scanf("%lld", &Q);

    long long int arr1[N];
    long long int *arra1[N];
    long long int *b;
    b = &i;

    char str[N];

    for (int i = 0; i < N; i++)
    {
        arr1[i] = i + 1;
    }
    preorder(root, b, arr1, arra1, H, str);

    for (long long int z = 0; z < Q; z++)
    {
        long long int T;
        scanf("%lld", &T);

        if (T == 2)
        {
            long long int L, R, I;
            scanf("%lld %lld %lld", &L, &R, &I);

            if (strncmp(S + L - 1, str + (*arra1[I - 1]) - 1, R - L + 1) == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

        else
        {
            long long int I;
            char C;
            scanf("%lld", &I);
            scanf(" %c", &C);
            str[(*arra1[I - 1]) - 1] = C;
        }
    }

    return 0;
}