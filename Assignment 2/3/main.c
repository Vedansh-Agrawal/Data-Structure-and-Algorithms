#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

int size(node *tail)
{
    if (tail == NULL)
    {
        return 0;
    }

    node *ptr;
    ptr = tail;

    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

int isEmpty(node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

int popfront(node **head, node **tail)
{
    node *ptr;
    ptr = *head;

    if (isEmpty(*head))
    {
        return 0;
    }

    int x = (*head)->data;
    if (*head == *tail)
    {
        *tail = NULL;
        *head = NULL;
    }
    else
    {
        *head = (*head)->prev;
    }

    free(ptr);
    return x;
}

int popback(node **tail, node **head)
{
    node *ptr;
    ptr = *tail;

    if (*tail == NULL)
        return 0;

    int x = (*tail)->data;
    if (*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = (*tail)->next;
    }
    free(ptr);
    return x;
}

void pushfront(node **tail, node **head, int x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = x;

    if (isEmpty(*head))
    {
        temp->next = NULL;
        temp->prev = NULL;
        *tail = temp;
        *head = temp;
    }

    else
    {
        temp->next = NULL;
        temp->prev = *head;
        (*head)->next = temp;
        *head = temp;
    }
}

void pushback(node **tail, node **head, int x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = x;

    if (isEmpty(*head))
    {
        temp->next = NULL;
        temp->prev = NULL;
        *tail = temp;
        *head = temp;
    }

    else
    {
        temp->next = *tail;
        temp->prev = NULL;
        (*tail)->prev = temp;
        *tail = temp;
    }
}

int front(node *head)
{
    if (isEmpty(head))
        return 0;
    return head->data;
}

int back(node *tail)
{
    if (tail == NULL)
        return 0;
    return tail->data;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    int N;
    long long int ans = 0;
    scanf("%d",&N);
    int value[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &value[i]);
    }

    pushback(&tail,&head,0);

    for (int i = 1;i<N;i++)
    {
        if (value[i] < value[front(head)])
        {
            ans += 2;
            pushfront(&tail,&head,i);
            continue;
        }

        while (value[i] > value[front(head)] && !isEmpty(head))
        {
           ans += i - front(head) + 1;
           popfront(&head,&tail); 
        }
        if (!isEmpty(head))
        {
            ans += i - front(head) + 1;
        }

        pushfront(&tail,&head,i);
    }
    printf("%lld",ans);

    return 0;
}