/* errmsg1.c 
   print all system error messages using "perror()"
   Since perror() sends results to standard error, you have to use
      a.out>&kkk to check the results.

*/

     #include <stdio.h>
     #include <errno.h>     

     int main()
     {
      int i;
      extern int errno;
  /*    extern const int sys_nerr; */
      extern int sys_nerr; 
      
       for (i = 0; i < sys_nerr; ++i) 
           {
           fprintf(stderr,"%3d",i);
           errno = i; 
           perror("***");
           }
       
        exit (0);
     }
