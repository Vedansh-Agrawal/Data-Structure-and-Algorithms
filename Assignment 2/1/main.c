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


node *head = NULL;
node *head1 = NULL;

long long int gcd(long long int a,long long int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

long long int lcm(long long int a, long long int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int N;
    long long int x;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &x);
        push(&head, x);
    }

    int count;

    do
    {
        count = 0;

        while (!isEmpty(head))
        {
            x = pop(&head);
            while (top(head) != 0 && gcd(x, top(head)) > 1)
            {
                head->data = lcm(x, top(head));
                x = pop(&head);
                count++;
            }
            push(&head1, x);
        }

        count = 0;

        while (!isEmpty(head1))
        {
            x = pop(&head1);
            while (top(head1) != 0 && gcd(x, top(head1)) > 1)
            {
                head1->data = lcm(x, top(head1));
                x = pop(&head1);
                count++;
            }
            push(&head, x);
        }
    } while (count != 0);

    while (!isEmpty(head))
    {
        x = pop(&head);
        push(&head1, x);
    }

    printf("%d\n", size(head1));
    while (top(head1) != 0)
    {
        printf("%lld ", pop(&head1));
    }

    return 0;
}