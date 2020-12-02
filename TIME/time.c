#include <sys/types.h>
#include <sys/times.h>
#include <stdio.h>
#include <unistd.h>

int plus(int iEnd)
{
    int i = 0;
    while(i < iEnd)
        i++;

    return i;
}


main(int argc, char *argv[])
{

struct tms t1,t2,t3,t4;
int i;
int j;

int iNum = 0;

    if (argc < 2)
    {
        printf("Usage : %s Num\n", argv[0]);
        return -1;
    }
 

   times(&t1);
 
   iNum = plus(atoi(argv[1]));    

   times(&t2);
  

 
  printf("user = %f\nsystem = %f\n",
    (t2.tms_utime - t1.tms_utime) / sysconf(_SC_CLK_TCK),
    (t2.tms_stime - t1.tms_stime) / sysconf(_SC_CLK_TCK));                      
  printf("\n");

}
