#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, M, ans = 0, temp, j;
    scanf("%d %d", &N, &M);

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (j = i; j < N - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                break;
            }
        }

        if (j == N - 1)
        {
            break;
        }

        if (arr[i] > M)
        {
            temp = arr[i];
            arr[i] = M;
            M = temp;
            ans++;
        }
    }

    for (j = 0; j < N - 1; j++)
    {
        if (arr[j + 1] < arr[j])
        {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}