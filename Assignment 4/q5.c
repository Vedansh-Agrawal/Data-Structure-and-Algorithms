#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int size = 0;

void swap(long long int *a, long long int *b)
{
    long long int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(long long int array[], int size, long long int i)
{
    if (size == 1)
    {
        return;
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest])
            largest = l;
        if (r < size && array[r] > array[largest])
            largest = r;
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}

void insert(long long int array[], long long int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        long long int x = size - 1;
        while (x > 0 && array[(x - 1) / 2] < array[x])
        {
            swap(&array[(x - 1) / 2], &array[x]);
            x = (x - 1) / 2;
        }
    }
}

void deleteRoot(long long int array[])
{
    swap(&array[0], &array[size - 1]);
    size -= 1;
    heapify(array, size, 0);
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int z = 0; z < t; z++)
    {
        int N;
        scanf("%d", &N);
        int arr[N][N];
        int arrs[N];
        

        for (int i = 0;i<N;i++)
        {
            for (int j = 0;j<N;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for (int i = 0;i<N;i++)
        {
            qsort(arr[i],N,sizeof(int),cmpfunc);
        }

        for (int i = 0;i<N;i++)
        {
            arrs[i] = arr[0][i];
        }


        for (int i = 1;i<N;i++)
        {
            size = 0;
            long long int heap[N];
            for (int j = 0;j<N;j++)
            {
                insert(heap,arrs[0] + arr[i][j]); 
            }

            for (int j = 1;j<N;j++)
            {
                for (int k = 0;k<N;k++)
                {
                    if (arrs[j] + arr[i][k] < heap[0])
                    {
                        deleteRoot(heap);
                        insert(heap,arrs[j] + arr[i][k]);
                    }
                    else
                    {
                        break;
                    }
                }
            }

            
            for (int j = 0;j<N;j++)
            {
                arrs[j] = heap[j];
            }
            qsort(arrs,N,sizeof(int),cmpfunc);
        }

        for (int i = 0;i<N;i++)
        {
            printf("%d ",arrs[i]);
        }
        printf("\n");
    }
}