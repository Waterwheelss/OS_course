/* gcc forktest2.c -lutil*/

#include<stdio.h>
#include<stdlib.h>
#include<pty.h>

int main()
{

int pty_pid;
int ptyfd,i;
int j;
char string[100];

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
                   printf("This_is_the_%d_iteration\n", i);
                   sleep(1);
        }
     printf("end\n");
     scanf("%s",string);
     printf("%s***\n",string);
 exit(0);
/* fputs("CHILD",stdout); */
}
else
{
   printf("I am the parent, ptyfd=%d\n",ptyfd);
   close(0);
   dup(ptyfd);
   for (j=0;j<5;j++)
   {
     scanf("%s",string);
     printf("%s***\n",string);
   }
   close(1);
   dup(ptyfd);
   printf("MessageFromMaster\n");
   execlp("cat","cat",NULL);
}
return 0;
}
