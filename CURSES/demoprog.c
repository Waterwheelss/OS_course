#include <curses.h>
#include <sys/signal.h>

   void initial();

   main()
   {
     WINDOW *win[3],*curwin,*helpwin;
     int nowwin;
     int x,y;
     int i,j;
     int ch;
     x=2;y=2;

     initial();

     nodelay(stdscr,TRUE);
     /*
     The nodelay option causes getch to be a non-blocking call.  If no input
       is ready, getch returns ERR.  If disabled (bf is  FALSE),  getch  waits
       until a key is pressed.
       */

     win[0]=newwin(LINES/3-1,COLS-1,0,0);       /* 設定兩個視窗的大小*/
     win[1]=newwin(LINES/3-1,COLS-1,LINES/3,0);
     win[2]=newwin(4,COLS-1,20,0);

     
     scrollok(win[0],TRUE);    
     scrollok(win[1],TRUE);    
     scrollok(win[2],TRUE);    
j=1;
for (;;)         
{
	j++;
   wprintw(win[0],"test%d for window1 \n",j);   
 /*  wrefresh(win[0]);
*/
   curwin=win[2];
   wmove(curwin,y,x);
   if ((ch = getch()) != ERR) {
   waddch(win[2],ch);
   wrefresh(win[2]);
   x++;
   }
   else
   {
	if ( (j%100)==0)  { wrefresh(win[0]); wrefresh(win[1]);}
   }
   wprintw(win[1],"test%d for window2 \n",j);
 /*  wrefresh(win[1]);
  */ 
}


}

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

