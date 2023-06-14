#include <stdio.h>

void merge_sort(int *, int *, int, int);
void merge(int *, int *, int, int);

int main(void)
{
  const int size = 8;
  int src[size] = {3, 19, 44, 58, 23, 5, 0, 45};
  int tar[size];

  merge_sort(src, tar, 0, size - 1);

  // print the output
  for (int i = 0; i < size; i++)
  {
    printf("%d ", tar[i]);
  }

  return 0;
}

void merge_sort(int *src, int *tar, int le, int ri)
{
  if (ri - le < 2)
  {
    if (src[ri] < src[le])
    {
      tar[ri] = src[le];
      tar[le] = src[ri];
    }
    return;
  }

  if (le < ri)
  {
    // divide
    int mid = (int)((le + ri) / 2);
    merge_sort(src, tar, le, mid);
    merge_sort(src, tar, mid + 1, ri);

    // conquer
    merge(src, tar, le, ri);
  }
}

void merge(int *src, int *tar, int le, int ri)
{
  int mid = (int)((le + ri) / 2);
  int i = le;      // left half
  int j = mid + 1; // right half
  int k = le;

  while (i <= mid && j <= ri)
  {
    // tar에 가장 작은 수부터 채워 넣기
    if (src[i] < src[j])
    {
      tar[k] = src[i];
      i++;
    }
    else
    {
      tar[k] = src[j];
      j++;
    }
    k++;
  }

  if (i > mid)
  { // 만약 right half 가 남았으면
    while (k <= ri)
    {
      tar[k] = src[j];
      j++;
    }
  }
  else
  { // 만약 left half 가 남았으면
    while (k <= ri)
    {
      tar[k] = src[i];
      i++;
    }
  }
}
