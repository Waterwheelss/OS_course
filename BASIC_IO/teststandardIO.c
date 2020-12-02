#include <stdio.h>

main()
{
 int i;

 printf("Hello world!\n");
 i=write(1,"Hello1\n",7);
 i=write(2,"Hello2\n",7);
 printf("The value of i is %d\n",i);
}
