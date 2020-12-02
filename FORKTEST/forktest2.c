#include<stdio.h>

main()
{

   int pid;

   printf("Start of test\n"); 
   pid=fork();
   printf("The valus of pid = %d, my process id is %d.\n",pid,getpid());

   switch(pid)
   {
     case -1:
       printf("The system can not create process now.\n");
       return;

     case 0:
       execlp("echo","echo","I am the child process",NULL);


     default:
       printf("I am the parent process\n");
   }
}
