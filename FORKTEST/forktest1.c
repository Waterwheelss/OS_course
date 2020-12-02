#include<stdio.h>

main()
{

   int pid,pid1;

   printf("Start of test. My process id is %d.\n",getpid()); 
   pid=fork();
   if (pid==0)
   {
    for (;;)
    {
     printf("(Child process)My pid is %d\n",pid);
     sleep(1);
    }
   }
   else
   {
    for (;;)
    {
     printf("(Parent process)My pid is %d\n",pid);
      sleep(1); 
    }
   }
   

}
