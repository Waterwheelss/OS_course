/* newdir.c 
        create a new directory, called newdir, using fork() and exec().
     */

     #include <fcntl.h>         /* defines options flags */
     #include <sys/types.h>     /* defines types used by sys/stat.h */
     #include <sys/stat.h>      /* defines S_IREAD & S_IWRITE  */
     #include <stdio.h>

     int main()
     {
        int fd;

        if ( fork() != 0)
           wait ((int *) 0);
        else
           {
           execl ("/bin/mkdir", "mkdir", "newdir", (char *) NULL);
           fprintf (stderr, "exec failed!\n");
           exit (1);
           }

        /*  now use newdir  */
        if ( (fd = open("newdir/foo.bar", O_RDWR | O_CREAT, 0644)) == -1)
           {
           fprintf (stderr, "open failed!\n");
           exit (2);
           }
        write (fd, "Hello, world\n", 14);
        close (fd);
        exit (0);
     }