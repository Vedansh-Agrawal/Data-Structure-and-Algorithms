#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(long long int a, long long int b)
{
    return (a < b);
}

long long int Max(long long int a, long long int b)
{
    return (a > b) ? a : b;
}

int main()
{
    long long int N;
    cin >> N;

    vector<long long int> score(N,0);
    for(int i = 0; i < N; i++)
    {
        cin >> score[i];
    }
    vector<long long int> new_arr(N,0);
    copy(begin(score), end(score), begin(new_arr));
    vector<long long int> alt_score(N,0);
    vector<long long int> rel_stud(N-1);
    vector<long long int> ctype(N-1);
    for(int i = 0; i < N-1; i++)
    {
        cin >> rel_stud[i] >> ctype[i];
    }
    long long int temp;
    for(int i = N-2; i >= 0; i--)
    {
        switch (ctype[i])
        {
            case 0:
                score[rel_stud[i]] += alt_score[i+1];
                alt_score[rel_stud[i]] = Max(alt_score[rel_stud[i]]+score[i+1], alt_score[rel_stud[i]]+alt_score[i+1]);
                break;
            case 1:
                //score[rel_stud[i]] = Max({score[rel_stud[i]]+alt_score[i+1], score[i+1]+alt_score[rel_stud[i]], score[rel_stud[i]]+score[i+1]}, comp);
                temp = Max(alt_score[rel_stud[i]]+score[i+1], score[rel_stud[i]]+score[i+1]);
                score[rel_stud[i]] = Max(temp, score[rel_stud[i]]+alt_score[i+1]);
                alt_score[rel_stud[i]] += alt_score[i+1];
                break;
            case 2:
                score[rel_stud[i]] = Max(alt_score[i+1]+score[rel_stud[i]],alt_score[rel_stud[i]]+ score[i+1]);
                alt_score[rel_stud[i]] += alt_score[i+1];
                break;
        }
    }
    cout << Max(score[0], new_arr[0]) << endl;
}