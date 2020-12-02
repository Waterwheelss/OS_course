#include <sys/types.h>
#include <sys/times.h>
#include <stdio.h>

#define RESOLUTION      10000

main()
{

struct tms t1,t2,t3,t4;
int i;
int j;
 

 times(&t1);
 
 for (i=0;i<10000;i++)
{
j++;
}     

  times(&t2);
  

 
  printf("user = %f\nsystem = %f\n",
    1000000/RESOLUTION*(t2.tms_utime - t1.tms_utime) / 60.0,
    1000000/RESOLUTION*(t2.tms_stime - t1.tms_stime) / 60.0);                      
  printf("\n");

}
