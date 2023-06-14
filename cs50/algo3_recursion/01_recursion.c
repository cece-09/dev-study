#include <stdio.h>

void draw(int);

int main(void)
{
  int num;
  printf("enter a number: ");
  scanf("%d", &num);

  draw(num);
}

void draw(int num)
{
  if (num == 0)
  {
    return;
  }

  draw(num - 1);

  for (int i = 0; i < num; i++)
  {
    printf("#");
  }
  printf("\n");
}