#include<stdio.h>

main()
{

   int pid,pid1,status;

   printf("Start of test\n"); 
   pid=fork();
   printf("===>The value of pid is %d\n",pid);

   switch(pid)
   {
     case -1:
       printf("The system can not create process now.\n");
       return;

     case 0:

       printf("Child process ID is %d\n",getpid());
       execlp("echo","echo","I am the child process",NULL);

     default:
       printf("I am the parent process\n");
       while( (pid1=wait(&status))!=-1)
       {
         printf("Child process %d terminates\n",pid1);
       }
   }
}
