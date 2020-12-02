#include<stdio.h>

main()
{
  int i;
  int j;

  i=getpid();
  j=getppid();
 
  printf("My process ID is %d, and my parent process ID is %d.\n",i,j);
}
