#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

static void error_exit(const char* msg);

int main() {
    void *addr;
    int prot = PROT_WRITE | PROT_READ;
    int mopt = MAP_SHARED | MAP_ANON;
    size_t pagesize = sysconf(_SC_PAGE_SIZE);
    
    addr = mmap(NULL, pagesize, prot, mopt, -1, 0);
    if(addr == MAP_FAILED)
        error_exit("mmap");

    // 공유 메모리에 데이터를 쓴다.
    sprintf(addr, "hello from pid %d", getpid());

    for(int i = 0; i < 10; ++i) {
        pid_t pid = fork();
        if(pid < 0)
            error_exit("fork");
        else if(pid == 0) {
            printf("[%d] child  see: %s\n", getpid(), addr); // 부모가 쓴 데이터를 본다
            // 자식이 새 데이터를 쓴다
            sprintf(addr, "hello from pid %d", getpid());
            if(munmap(addr, pagesize) < 0)
                error_exit("munmap");
            exit(EXIT_SUCCESS);
        } else {
            if(wait(NULL) < 0)
                error_exit("wait");
        }
    }

    // 마지막 자식 종료 후 데이터 확인
    printf("[%d] parent see: %s\n", getpid(), addr);
    if(munmap(addr, pagesize) < 0)
        error_exit("munmap");
    
    return 0;
}

static void error_exit(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}