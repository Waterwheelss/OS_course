 /*  dup.c
           demonstrate redirection of standard output to a file.
     */

     #include <stdio.h>
     #include <fcntl.h>
     #include <sys/types.h>
     #include <sys/stat.h>

     int main()
     {
        int fd;

        printf("First message\n");

        fd = open("foo.bar",O_WRONLY | O_CREAT, S_IREAD | S_IWRITE );
        if (fd == -1)
           {
           perror("foo.bar");
           exit (1);
           }
        close(1);         /* close standard output  */
        
	printf("Second message\n");
        
	dup(fd);       /* fd will be duplicated into standard out's slot */
        close(fd);        /* close the extra slot */
        execlp("who","who",NULL);
        exit (0);         /* exit() will close the files */
     }
