#include <bits/stdc++.h>
typedef long long int lli;



int main()
{
    lli N;
    scanf("%lld", &N);

    lli ability[N];
    lli p[N], q[N];
    for (lli i = 0; i < N; i++)
    {
        scanf("%lld", &ability[i]);
        p[i] = ability[i];
    }

    for(lli i=0;i<N;i++)
    {
        q[i] = 0;
    }

    lli lol = 2 * (N - 1);

    lli ref[(lol / 2)] ;
    lli connection[(lol / 2)];

    for (lli z = 0; z < lol/2; z++)
    {
        scanf("%lld %lld", &ref[z], &connection[z]);
    }

    for (lli z = ((lol / 2) - 1); z >= 0; z--)
    {
        if (connection[z] == 2)
        {
            lli max = 0;

            if (p[ref[z]] + q[z+1] >= p[z+1] + q[ref[z]])
            {
                max = p[ref[z]] + q[z+1];
            }
            else
            {
                max = p[z+1] + q[ref[z]];
            }

            p[ref[z]] = max;

            q[ref[z]] = q[ref[z]] + q[z+1];
        }
        else if (connection[z] == 1)
        {
            lli max_temp = 0;
            lli max1 = 0;

            if (p[ref[z]] + q[z+1] >= p[z+1] + q[ref[z]])
            {
                max_temp = p[ref[z]] + q[z+1];
            }
            else
            {
                max_temp = p[z+1] + q[ref[z]];
            }

            if (max_temp >= p[ref[z]] + p[z+1])
            {
                max1 = max_temp;
            }
            else
            {
                max1 = p[ref[z]] + p[z+1];
            }

            p[ref[z]] = max1;

            q[ref[z]] = q[ref[z]] + q[z+1];
        }
        else
        {
            lli max2;

            if(p[z] + q[ref[z]] >= q[ref[z]] + q[z])
            {
                max2 = p[z+1] + q[ref[z]];
            }
            else
            {
                max2 = q[ref[z]] + q[z+1] ;
            }

            p[ref[z]] = p[ref[z]] + q[z+1] ;

            q[ref[z]] = max2;
        }
    }

    lli ans;

    if(p[0]>q[0])
    {
        ans = p[0];
    }
    else
    {
        ans = q[0];
    }

    printf("%lld\n",ans);
}