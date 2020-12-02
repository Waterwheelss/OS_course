#include<stdio.h>

main()
{

   int pid,pid1;

   printf("Start of test. My process id is %d.\n",getpid()); 
   pid=fork();
   printf("(First)My pid is %d. My process ID=%d\n",pid,getpid());
   
   pid1=fork();
   printf("(Second)My pid is %d. My process ID=%d\n",pid,getpid());
   


   

}
