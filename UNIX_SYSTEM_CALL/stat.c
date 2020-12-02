 /*  status.c  */
     /*  demonstrates the use of the stat() system call to determine the
         status of a file.
     */

     #include <stdio.h>
     #include <sys/types.h>
     #include <sys/stat.h>

     #define ERR   (-1)
     #define TRUE  1
     #define FALSE 0

     int main();

     int main(argc, argv)
     int argc;
     char *argv[];

     {
        int isdevice = FALSE;
        struct stat stat_buf;

        if (argc != 2)
           {
           printf("Usage:  %s filename\n", argv[0]);
           exit (1);
           }
        if ( stat( argv[1], &stat_buf) == ERR)
           {
           perror("stat");
           exit (1);
           }
        printf("\nFile:  %s  status:\n\n",argv[1]);
        if ((stat_buf.st_mode & S_IFMT) == S_IFDIR)
           printf("Directory\n");
        else if ((stat_buf.st_mode & S_IFMT) == S_IFBLK)
           {
           printf("Block special file\n");
           isdevice = TRUE;
           }
        else if ((stat_buf.st_mode & S_IFMT) == S_IFCHR)
           {
           printf("Character special file\n");
           isdevice = TRUE;
           }
        else if ((stat_buf.st_mode & S_IFMT) == S_IFREG)
           printf("Ordinary file\n");
        else if ((stat_buf.st_mode & S_IFMT) == S_IFIFO)
           printf("FIFO\n");
        if (isdevice)
           printf("Device number:%d, %d\n", (stat_buf.st_rdev > 8) & 0377,       
                  stat_buf.st_rdev & 0377);
        printf("Resides on device:%d, %d\n", (stat_buf.st_dev > 8) & 0377,       
                stat_buf.st_dev & 0377);
        printf("I-node: %d; Links: %d; Size: %ld\n", stat_buf.st_ino,             
               stat_buf.st_nlink, stat_buf.st_size);
        if ((stat_buf.st_mode & S_ISUID) == S_ISUID)
           printf("Set-user-ID\n");
        if ((stat_buf.st_mode & S_ISGID) == S_ISGID)
           printf("Set-group-ID\n");
        if ((stat_buf.st_mode & S_ISVTX) == S_ISVTX)
           printf("Sticky-bit set -- save swapped text after use\n");
        printf("Permissions: %o\n", stat_buf.st_mode & 0777);

        exit (0);
     }