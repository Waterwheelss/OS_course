/* errmsg2.c
        print all system error messages using the global error message table.
     */

     #include <stdio.h>
     #include <errno.h>

     int main()
     {
        int i;
     /*   extern const int sys_nerr;
        extern const char * const sys_errlist[];
      */
        extern int sys_nerr;
        extern char *sys_errlist[];

      fprintf(stderr,"Here are the current %d error messages:\n\n",sys_nerr);
      for (i = 0; i < sys_nerr; ++i)
         fprintf(stderr,"%3d: %s\n", i, sys_errlist[i]);
     }
