#include <stdio.h>

main()
{ 
  int pid;

  printf("Start of the program\n");
  pid=fork();

  printf("The value of pid is %d. My PID is %d, My PPID is %d\n",pid,getpid(),getppid());

}
