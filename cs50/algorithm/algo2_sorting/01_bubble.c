#include <stdio.h>

// func
void swap(int *, int *);
void show(int *, int);

int main(void)
{
  const int size = 8;
  int array[size] = {3, 19, 44, 58, 23, 5, 0, 45};

  int isSwapped;

  // bubble sort
  for (int i = 0; i < size; i++)
  {
    isSwapped = 0;
    for (int j = 0; j < size; j++)
    {
      int prev = j;
      int next = j + 1;
      if (array[prev] > array[next])
      {
        swap(&array[prev], &array[next]);
        isSwapped = 1;
      }
    }
    // 교환이 일어나지 않으면 정렬 완료
    // 교환이 일어나지 않을 때 까지만 루프 수행 -> 실행 시간 개선
    if (!isSwapped)
      break;
  }

  show(array, size);

  return 0;
}

void swap(int *prev, int *next)
{
  int tmp = *prev;
  *prev = *next;
  *next = tmp;

  return;
}

void show(int *array, int size)
{
  // output
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}