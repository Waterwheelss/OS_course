#include <sys/types.h>
#include <sys/times.h>
#include<stdio.h>
#define RESOLUTION      10000


main()
{
  int i;
  int j;
  struct tms t1,t2,t3,t4;

  times(&t1);

  i=getpid();
  j=getppid();

  for (i=0;i<10000;i++)
  {
    for (j=0;j<10000;j++)
    {
      
    }
  }



  times(&t2);

  printf("My process ID is %d, and my parent process ID is %d.\n",i,j);

  printf("\nuser = %f\nsystem = %f\n",
      1000000/RESOLUTION*(t2.tms_utime - t1.tms_utime) / 60.0,
          1000000/RESOLUTION*(t2.tms_stime - t1.tms_stime) / 60.0);                      
	    printf("\n");

}

