#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
 
main()
{

    key_t key;
    int msqid,i;
    char buf[255];

    key = ftok("/home/beej/somefile", 'b');
    msqid = msgget(0x887, IPC_CREAT|0660);
    
    i=msgrcv(msqid, &buf,255, 0, 0);  	  
    if (i>0)
    { printf("The receiver has successfully received the message.\n");
      printf("The message is => %s\n", buf);
    }
    else {perror("***");}
}	    
