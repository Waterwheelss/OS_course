#include<stdio.h>

main()
{

   int i,pid,pid1,status,counter,number;

   counter=0;
   printf("Start of test\n"); 
   printf("How many process do you want to creat?");
   scanf("%d",&number);

 for (i=0;i<number;i++)
 {
   pid=fork();
   switch(pid)
   {
     case -1:
       printf("The system can not create process for you now.\n");
       return;
     case 0:
       printf("Child process ID is %d\n",getpid());
       sleep(3);
       execlp("echo","echo","I am the child process",NULL);
     default:
       counter++;
       
       printf("I have created %d processes\n",counter);
     }
   }

       while( (pid1=wait(&status))!=-1)
       {
         printf("Child process %d terminates\n",pid1);
       }



}
