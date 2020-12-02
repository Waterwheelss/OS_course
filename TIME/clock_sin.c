#include <stdio.h>
#include <time.h>
#include <math.h>

/* gcc clock_sin.c -lm*/
/* This sample will display how to calculate the program execution time */

int plus(int iEnd)
{
    int i = 0;
    double d=0;
    while(i < iEnd)
    {    i++;
      d=sin(0.1*i);
    }
    return i;
}

int main(int argc, char *argv[])
{
    clock_t start_time, end_time,total_clock;
    float total_time = 0;
    int iNum = 0;
    if (argc < 2)
    {
        printf("Usage : %s Num\n", argv[0]);
        return -1;
    }

    start_time = clock(); /* mircosecond */
    iNum = plus(atoi(argv[1]));
    sleep(1);
    end_time = clock();

    /* CLOCKS_PER_SEC is defined at time.h */
    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
    total_clock = end_time - start_time;
    printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
    printf("Clock : %ld \n", total_clock);
    printf("Time : %f sec \n", total_time);

    return 0;
}

