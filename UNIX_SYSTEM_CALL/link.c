/*  link.c
     */

     #include <stdio.h>

     int main()
     {
        if ((link("foo.old", "foo.new")) == -1)
           {
           perror(" ");
           exit (1);         /* return a non-zero exit code on error */
           }
        exit(0);
     }