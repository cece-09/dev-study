/* sbrk and brk example */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    void *curr_brk, *tmp_brk = NULL;
    tmp_brk = curr_brk = sbrk(0);
    printf("program break location: %p\n", curr_brk);

    brk(curr_brk+0x3000);
    curr_brk = sbrk(0); // 재초기화
    printf("program break location: %p\n", curr_brk);

    brk(tmp_brk);
    curr_brk = sbrk(0);
    printf("program break location: %p\n", curr_brk);

    return 0;
}