#define SHMKEY ((key_t) 1235)
#define PERMS 0666

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shmid;
char *mesgptr;

main()
{
  shmid = shmget(SHMKEY,1000,PERMS|IPC_CREAT);
  mesgptr = (char *)shmat(shmid,(char *)0,0);
  strcpy(mesgptr,"777btest 1234345 share memory again");
  shmdt(mesgptr);
}

