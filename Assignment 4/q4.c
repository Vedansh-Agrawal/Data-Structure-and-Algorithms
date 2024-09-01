#include <stdio.h>

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
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest])
      smallest = l;
    if (r < size && array[r] < array[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&array[i], &array[smallest]);
      heapify(array, size, smallest);
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
    while (x > 0 && array[(x - 1)/2] > array[x])
    {
      swap(&array[(x - 1)/2],&array[x]);
      x = (x - 1)/2;
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
  int N;
  long long int sum = 0;
  scanf("%d %d", &N, &size);

  long long int arr[size];

  for (int i = 0; i < size; i++)
  {
    scanf("%lld", &arr[i]);
  }

  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(arr, size, i);
  }

  while (size > 1)
  {
    long long int a = arr[0];
    deleteRoot(arr);
    long long int b = arr[0];
    deleteRoot(arr);

    sum += a + b;
    insert(arr, a + b);
  }

  printf("%lld", sum);
}