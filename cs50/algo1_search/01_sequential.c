#include <stdio.h>

int main(void)
{
  const int size = 8;
  int array[size] = {3, 19, 44, 58, 23, 5, 0, 45};

  int tar;
  printf("Search: ");
  scanf("%d", &tar);

  // sequential search
  for (int i = 0; i < size; i++)
  {
    if (array[i] == tar)
    {
      printf("Found %d in index %d\n", tar, i);
      return 0;
    }
  }

  printf("Not Found\n");
  return 0;
}