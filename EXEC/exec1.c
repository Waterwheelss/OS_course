#include<stdio.h>

main()
{
  printf("My program starts to execute\n");

  execlp("ls","ls","-a",NULL);
 
}
