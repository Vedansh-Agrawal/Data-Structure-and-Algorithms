#include <stdio.h>
#include <string.h>
#include "my_dll.h"
#include "node.h"

int main()
{
    my_dll listi;
    listi.root = NULL;
    listi.tail = NULL;
    my_dll *list;
    list = &listi;

    while (1)
    {
        char key[15];
        int data;

        scanf("%s", key);
        if (strcmp(key, "insert") == 0)
        {
            scanf("%d", &data);
            insert(list, data);
        }

        else if (strcmp(key, "insert_at") == 0)
        {
            int i;
            scanf("%d", &data);
            scanf("%d", &i);
            insert_at(list, data, i);
        }

        else if (strcmp(key, "delete") == 0)
        {
            int i;
            scanf("%d", &i);
            delete (list, i);
        }

        else if (strcmp(key, "find") == 0)
        {
            int x;
            scanf("%d", &data);
            x = find(list, data);
            printf("%d\n", x);
        }

        else if (strcmp(key, "prune") == 0)
        {
            prune(list);
        }

        else if (strcmp(key, "print") == 0)
        {
            print(list);
        }

        else if (strcmp(key, "print_reverse") == 0)
        {
            print_reverse(list);
        }

        else if (strcmp(key, "get_size") == 0)
        {
            int x;
            x = get_size(list);
            printf("%d\n", x);
        }
    }
    return 0;
}