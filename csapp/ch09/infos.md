##### 1. 시스템의 리소스 제한 확인하기
리눅스에서 ulimit을 사용해 시스템의 리소스 제한을 확인할 수 있다.
```shell
ulimit -u // 동시에 실행할 수 있는 프로세스의 최대 수
ulimit -n // 열 수 있는 파일의 최대 수
ulimit -l // 스택의 최대 크기
```

##### 2. 페이지 폴트의 수 확인하기
 ```c
#include <sys/resource.h>
#include <sys/time.h>
struct rusage r_usage;

  if (getrusage(RUSAGE_SELF, &r_usage) != 0) {
    perror("getrusage");
    return 1;
  }

  // ...

  // 사용자 CPU 시간과 시스템 CPU 시간을 출력한다.
  printf("User CPU time: %ld.%06ld sec\n", r_usage.ru_utime.tv_sec,
         r_usage.ru_utime.tv_usec);
  printf("System CPU time: %ld.%06ld sec\n", r_usage.ru_stime.tv_sec,
         r_usage.ru_stime.tv_usec);

  // 페이지 폴트 횟수를 출력한다.
  printf("Soft page faults: %ld\n", r_usage.ru_minflt);
  printf("Hard page faults: %ld\n", r_usage.ru_majflt);
```

또는 명령줄에서 `perf` 도구를 사용하여 확인
```bash
perf stat -e page-faults ./test

// result
Performance counter stats for './test':

        50      page-faults:u                                               

0.000710726 seconds time elapsed

0.000715000 seconds user
0.000000000 seconds sys
```
