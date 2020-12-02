#include<stdio.h>

main()
{

   int pid,pid1;

   printf("Start of test.\n "); 
   pid=fork();
   printf("My process ID is %d\n",pid);
   
   pid=fork();
   printf("My process ID is %d\n",pid);
   


   

}
