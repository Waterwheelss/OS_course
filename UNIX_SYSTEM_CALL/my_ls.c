/*  my_ls.c
         This program simulates the System V style ls -a command.  Filenames
         are printed as they occur in the directory -- no sorting is done.
     */

     #include <stdio.h>
     #include <fcntl.h>
     #include <sys/types.h>
     #include <sys/dir.h>

     #define  ERR  (-1)

     int main()
     {
        int fd;
        struct direct dir;

        if (( fd = open ("/usr/include/sys", O_RDONLY)) == ERR)      /* open current directory */
           {
           perror("open");
           exit (1);
           } else printf("The open of . is successful %d\n",sizeof(struct direct));
           
        while (( read (fd, &dir, sizeof(struct direct)) > 0 ))
           {
           if ( dir.d_ino == 0 )               /* is it a deleted file?  */
              continue;                        /* yes, so go read another */

           /* make sure we print no more than DIRSIZ characters  */
          /*printf ("file=>\n");
          printf ("size=%d\n", dir.d_namlen);*/
          printf ("%s\n", dir.d_name);
         
           }
        close (fd);
        exit (0);
     }