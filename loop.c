#include <stdio.h>

main()
{
  int i;

  for (i=1;i<10000;i++)
  {
  printf("Hello! Thanks i=%d\n",i);
  sleep(1);
  }
}
