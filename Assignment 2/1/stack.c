

int pop(node **head)
{
    node *ptr;
    ptr = *head;

    if (isEmpty(*head))
    {
        return 0;
    }

    *head = (*head)->next;
    int x = ptr->data;
    free(ptr);
    return x;
}

void push(node **head, int x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = x;

    temp->next = *head;
    *head = temp;
}

int top(node *head)
{
    if (isEmpty(head))
        return 0;
    return head->data;
}

int isEmpty(node *head)
{
    return (head == NULL);
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