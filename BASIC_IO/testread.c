#include<stdio.h>

main()
{

   int fd,size,i;
   char filename[100];
   char buf[100];   

   printf("Input the file name to open:\n"); 
   scanf("%s",filename);

   fd=open(filename,0);
   
   printf("The file descriptor is %d.\n",fd);
   
   while ((size=read(fd,buf,sizeof(buf)))>0)
   {
     printf("%d bytes are read.\n",size);
      
   /*  for (i=0;i<size;i++)
       printf("%C",buf[i]);
   */ 
   }
	  
   close(fd);
}
