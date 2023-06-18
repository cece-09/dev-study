#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

/* functions */
void create(node *);
void deallocate(node *);
void insert(node *, node, int);
void show(node *);

int main(void)
{
  node *list, *next, *prev; // 연결 리스트의 시작, 현재, 이전 포인터
  int size, idx, tmp;       // 리스트 크기, 인덱스, 임시값

  size = 0;
  idx = 0;

  // create list
  while (1)
  {
    tmp = 0;
    printf("Enter an integer: ");
    scanf("%d", &tmp);

    // 루프 종료
    if (tmp < 0)
    {
      printf("Terminate Input Sequence.\n");
      break;
    }

    // 새로운 노드 생성
    next = malloc(sizeof(node));
    next->number = tmp;
    next->next = NULL;

    // 리스트의 첫 노드인 경우 고려해 링크
    list = !size ? next : list;
    prev->next = !size ? NULL : next; // 링크

    // 다음 원소로
    prev = next;
    size++;
  }

  show(list);

  node new = {20, NULL};
  insert(list, new, 1);
  show(list);

  // 메모리 해제
  // deallocate(list);
}

void deallocate(node *list)
{
  node *curr = list;
  node *next = list;
  while (curr)
  {
    next = curr->next;
    if (!next)
    {
      free(curr);
      break;
    }
    free(curr);
    curr = next;
  }
}

void insert(node *list, node new, int idx)
{
  int cnt = 0;
  node *curr = list;
  node *next;

  while (curr)
  {
    if (!curr)
      exit(-1); // 예외처리

    if (cnt == idx)
    {
      next = curr->next; // 원래 다음 노드
      curr->next = &new; // 현재노드의 다음 노드로 새로운노드 링크
      new.next = next;   // 새로운노드의 다음 노드로 원래 다음 노드 링크
      break;
    }
    curr = curr->next;
    cnt++;
  }
}

void show(node *list)
{
  while (list)
  {
    printf("[%p] %d --> [%p]\n", list, list->number, list->next);
    list = list->next;
  }
}