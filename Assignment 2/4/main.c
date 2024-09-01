#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    long long int data;
    struct node *next;
} node;

int isEmpty(node *head)
{
    return (head == NULL);
}

long long int pop(node **head)
{
    node *ptr;
    ptr = *head;

    if (isEmpty(*head))
    {
        return 0;
    }

    *head = (*head)->next;
    long long int x = ptr->data;
    free(ptr);
    return x;
}

void push(node **head, long long int x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = x;

    temp->next = *head;
    *head = temp;
}

long long int top(node *head)
{
    if (isEmpty(head))
        return 0;
    return head->data;
}

int size(node *head)
{
    node *ptr;
    ptr = head;
    if (isEmpty(head))
    {
        return 0;
    }

    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

void prevs(int N, int A[], int ps[])
{
    node *s = NULL;

    for (int i = 0; i < N; i++)
    {
        while (!isEmpty(s) && A[i] <= A[top(s)])
        {
            pop(&s);
        }

        if (isEmpty(s))
        {
            ps[i] = -1;
        }
        else
        {
            ps[i] = top(s);
        }

        push(&s, i);
    }
}

void nexts(int N, int A[], int ps[])
{
    node *s = NULL;

    for (int i = N - 1; i >= 0; i--)
    {
        while (!isEmpty(s) && A[i] <= A[top(s)])
        {
            pop(&s);
        }

        if (isEmpty(s))
        {
            ps[i] = N;
        }
        else
        {
            ps[i] = top(s);
        }

        push(&s, i);
    }
}

int maxarea(int N, int A[])
{
    int ps[N];
    int ns[N];

    prevs(N, A, ps);
    nexts(N, A, ns);

    int max,x;

    max = (ns[0] - ps[0] - 1) * A[0];

    for (int i = 1;i<N;i++)
    {
        x = (ns[i] - ps[i] - 1) * A[i];
        if (x > max)
        {
            max = x;
        }
    }
    return max;
}

int main()
{
    int N, M;
    char ch;
    scanf("%d %d", &N, &M);

    int A[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &ch);
            if (ch == '.')
                A[i][j] = 1;
            else
                A[i][j] = 0;

            if (i != 0)
            {
                if (A[i][j] == 1)
                {
                    A[i][j] += A[i - 1][j];
                }
            }
        }
    }

    int max;
    max = maxarea(M,A[0]);

    for (int i = 1;i<N;i++)
    {
        int x = maxarea(M,A[i]);
        if (x > max)
        {
            max = x;
        }
    }

    printf("%d\n",max);

    return 0;
}