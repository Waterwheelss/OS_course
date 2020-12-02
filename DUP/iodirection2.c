
#include<stdio.h>

main()
{
   int fd1,fd2;
   int pid,pid1;
   int status;


   printf("Start---->\n"); 

   fd1=open("text",0);
   fd2=creat("output",0666);

   printf("file descriptor number=%d,%d\n",fd1,fd2);

   pid=fork();
   switch(pid)
   {
     case -1:
       printf("The system can not create process now.\n");
       return;

     case 0:
       close(0);
       dup(fd1);
       close(1);
       dup(fd2);
       execlp("grep","grep","is",NULL);
     default:
       printf("I am the parent process.\n");
   }

       while( (pid1=wait(&status))!=-1)
       {
         printf("Child process %d terminates\n",pid1);
       }
}
