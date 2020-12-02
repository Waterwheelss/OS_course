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
    shmid = shmget(SHMKEY,1000,0);
    mesgptr = (char *)shmat(shmid,(char *)0,0);
    printf("%s\n",mesgptr);
    shmdt(mesgptr);
}


