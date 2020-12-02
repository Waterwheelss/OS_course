#include<stdio.h>

main()
{

   int fd;
   char filename[100];
   

   printf("Input the file name to open:\n"); 
   scanf("%s",filename);

   fd=open(filename,0);
   printf("The file descriptor is %d.\n",fd);
   
   

   printf("Input the file name to open:\n"); 
   scanf("%s",filename);

   fd=open(filename,0);
   printf("The file descriptor is %d.\n",fd);
   close(fd);
}
