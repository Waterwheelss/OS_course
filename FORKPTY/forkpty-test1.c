/* gcc forktest2.c -lutil*/

#include<stdio.h>
#include<stdlib.h>
#include<pty.h>

int main()
{

int pty_pid;
int ptyfd,i;

/* Create a new process on a new pty */
pty_pid = forkpty(&ptyfd, NULL, NULL, NULL);

if (pty_pid == -1)
{
   printf("error forking pty");
   exit(0);
}
else if (pty_pid == 0)
{
/* I am the new process */
   for (i=0;i<10;i++)
    {
                   printf("This is the %d iteration\n", i);
                   sleep(1);
        }
 exit(0);
/* fputs("CHILD",stdout); */
}
else
{
   close(0);
   dup(ptyfd);
   execlp("cat","cat",NULL);
}
return 0;
}
