#define SHMKEY ((key_t) 1235)
#define PERMS 0666

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shmid;
char *mesgptr;
int i;

main()
{
  shmid = shmget(SHMKEY,1000,PERMS|IPC_CREAT);
  mesgptr = (char *)shmat(shmid,(char *)0,0);
  for (i=0;i<100;i++)
  {  strcpy(mesgptr,"I am writer two\n");
     sleep(1);
     printf("I am process %d,i=%d\n", getpid(),i);
  }
  shmdt(mesgptr);
}

