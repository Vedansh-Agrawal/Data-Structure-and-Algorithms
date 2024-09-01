#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   if(*(long long int*)a - *(long long int*)b==0)
   {
       return 0;
   }
   else if(*(long long int*)a - *(long long int*)b>0)
   {
       return 1;
   }
   else
   {
       return -1;
   }
}

int main()
{
    long long int N,M,ans;
    scanf("%lld %lld",&N,&M);

    if (N == 1)
    {
        long long int x;
        scanf("%lld",&x);
        printf("%lld",x);
        return 0;
    }

    long long int arr[N];
    long long int arrs[N - 1];

    for (long long int i = 0;i<N;i++)
    {
        scanf("%lld",&arr[i]);
    }

    arrs[N-2] = arr[N-1];

    for (long long int i = N - 3;i>=0;i--)
    {
        arrs[i] = arrs[i + 1] + arr[i + 1];
    }

    ans = arrs[0] + arr[0];

    qsort(arrs,N - 1,sizeof(long long int),cmpfunc);

    for (long long int i = N - 2;i >= N - M;i--)
    {
        ans += arrs[i];
    }

    printf("%lld",ans);
    return 0;
}