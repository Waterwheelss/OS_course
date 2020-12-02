#include<stdio.h>

main()
{

   int fd,pid,size;
   char filename[100];
   char buf[100];

   printf("Input the file name to open:\n"); 
   scanf("%s",filename);

   fd=open(filename,0);
   
   printf("The file descriptor is %d.\n",fd);

   if ((size=read(fd,buf,10))>0)
   { printf("I am parent process. I read %d bytes\n", size); }
   
   pid=fork();
   
   switch(pid)
   {
   case -1:
      printf("The system can not create process now.\n");
      return;

   case 0:

      while ((size=read(fd,buf,50))>0)
      {
         printf("%d bytes are read by child.\n",size);
	 sleep(1);
        }

   default:
      while ((size=read(fd,buf,50))>0)
      {
         printf("%d bytes are read by parent.\n",size);
	 sleep(1);
        }
   
   
   }
   
	   
}
