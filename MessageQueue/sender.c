#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
 
main()
{

    int msqid;
    char *buf="I enjoy the OS course very much.\n";

    msqid = msgget(0x887, IPC_CREAT|0666);

    printf("To send %d bytes\n",strlen(buf));
    
    msgsnd(msqid, buf, strlen(buf), 0);  /* stick him on the queue */
    printf("The sender has successfully sent the message\n");
}	    
