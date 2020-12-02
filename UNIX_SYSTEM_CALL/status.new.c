/* status.c
        demonstrates exit() returning a status to wait().
     */

     int main()
     {
        int status=5;
        int retvalue;

        if ( fork () == 0 )  {       /*  == 0 means in child  */
        	 printf("The pid of child process is %d\n",getpid());
           scanf ("%d", &status);
           printf("Child execution\n");
           exit (status);
        }
        else  {                      /* != 0 means in parent */
        	 printf("Parent execution\n");
           retvalue=wait (&status);
           printf("return value is %d, child exit status = %d\n", retvalue, status>>8);
        }
     }