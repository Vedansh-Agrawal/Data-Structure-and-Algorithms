#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int Q;
    scanf("%d", &Q);

    for (int z = 0; z < Q; z++)
    {
        int n,x = 0;
        scanf("%d", &n);
        int arr[n];

        int arrs[n];

        for (int i = 0; i < n; i++)
        {
            arrs[i] = 0;
        }

        arrs[0] = 1;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        qsort(arr,n,sizeof(int),cmpfunc);

        for (int i = 1;i<n;i++)
        {
            if (arr[i] != arr[i-1])
            {
                x++;
            }

            arrs[x] += 1;
        }

        int max = 0, maxcount = 0;

        for (int i = 0; i < n; i++)
        {
            if (arrs[i] > max)
            {
                max = arrs[i];
                maxcount = 1;
            }

            else if (arrs[i] == max)
            {
                maxcount++;
            }
        }

        if (max == 1)
        {
            printf("%d\n", n);
            continue;
        }

        int ans = ((n - (maxcount - 1)) - max) / (max - 1);

       printf("%d\n",ans);
    }
    return 0;
}