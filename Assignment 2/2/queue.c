
int dequeue(node **head)
{
    node *ptr;
    ptr = *head;

    if (isEmpty(*head))
    {
        return 0;
    }

    int x = (*head)->data;
    *head = (*head)->prev;

    free(ptr);
    return x;
}

void enqueue(node **tail, node **head, int x)
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

int isEmpty(node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}

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