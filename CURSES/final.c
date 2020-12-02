 #include <curses.h>

   void initial();

   main()
   {
     WINDOW *win[3],*curwin,*helpwin;
     int nowwin;
     int x,y;
     int i,j;
     int ch;
     int pid;


     initial();

     

pid=fork();

 switch(pid)
 {
       case -1:
        printf("The system can not create process now.\n");
       return;

       case 0:
     
        win[0]=newwin(LINES/3-1,COLS-1,0,0);       /* 設定兩個視窗的大小*/
         win[1]=newwin(LINES/3-1,COLS-1,LINES/3,0);


           for (i=0;i<COLS-1;++i)              /* 畫兩個視窗間的界限 */
           mvaddch(LINES/2-1,i,'-');

    /*       nowwin=0;                          
           curwin=win[nowwin];
           getyx(curwin,y,x);
           move(0,0);
           refresh();
     */
          refresh();

         scrollok(win[0],TRUE);    
         scrollok(win[1],TRUE);
	for (j=0;j<100;j++)         
	{			              
   		wprintw(win[0],"test%d for window1 pid=%d\n",j,getpid());   
   		wrefresh(win[0]);
   		wprintw(win[1],"test%d for window2 pid=%d\n",j,getpid());
   		wrefresh(win[1]);
		sleep(1);
	}
       exit(1);
       default:
       win[2]=newwin(18,COLS-1,3,0);
           nowwin=0;                          
           curwin=win[nowwin];
           getyx(curwin,y,x);
           move(0,0);
         ch=getch();     
	 waddch(curwin,ch);
 }


  getch();
} /*End of main*/ 

   void initial()
   {
     initscr();                  
     cbreak();                   
     nonl();                     
     noecho();                  
     intrflush(stdscr,FALSE);
     keypad(stdscr,TRUE);
     refresh();
   }
