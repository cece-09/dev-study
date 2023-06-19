#include <stdio.h>

// func
void swap(int *, int *);
void show(int *, int);

int main(void)
{
  const int size = 8;
  int array[size] = {3, 19, 44, 58, 23, 5, 0, 45};

  int min;

  // selection sortss
  for (int i = 0; i < size; i++)
  {
    min = i;
    for (int j = i; j < size; j++)
    {
      if (array[j] < array[min])
      {
        min = j; // find and update the min
      }
    }
    swap(&array[i], &array[min]);
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