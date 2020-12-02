/*  unlink.c
     */

     #include <stdio.h>

     int main()
     {
        if ((unlink("foo.bar")) == -1)
           {
           perror(" ");
           exit (1);         /* return a non-zero exit code on error */
           }
        exit (0);
     }