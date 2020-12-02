
#include<stdio.h>

main()
{
   int fd;
   int pid,pid1;
   int status;


   printf("Start---->\n"); 

   fd=open("text",0);

   printf("file descriptor number=%d\n",fd);

   pid=fork();
   switch(pid)
   {
     case -1:
       printf("The system can not create process now.\n");
       return;

     case 0:
       close(0);
       dup(fd);
       execlp("cat","cat",NULL);
     default:
       printf("I am the parent process.\n");
   }

       while( (pid1=wait(&status))!=-1)
       {
         printf("Child process %d terminates\n",pid1);
       }
}
