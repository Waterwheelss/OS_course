/* remove.c  */

     #include <stdio.h>
     #include <sys/file.h>

     #define ERR   (-1)

     int main();

     int main(argc, argv)
     int argc;
     char *argv[];

     {

        if (argc != 2)
           {
           printf("Usage:  %s filename\n", argv[0]);
           exit (1);
           }
        if (access (argv[1], F_OK) == ERR)    /* check that file exists */
           {
           perror(argv[1]);
           exit (1);
           }
        if (access (argv[1], W_OK) == ERR)    /* check for write permission */
           {
           fprintf(stderr,"File:  %s  is write protected!\n", argv[1]);
           exit (1);
           }
        if (unlink (argv[1]) == ERR)
           {
           perror(argv[1]);
           exit (1);
           }
        exit (0);
     }