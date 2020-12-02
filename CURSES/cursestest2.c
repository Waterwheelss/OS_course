 #include <curses.h>

   void initial();

   main()
   {
     WINDOW *win[2],*curwin,*helpwin;
     int nowwin;
     int x,y;
     int i;
     int ch;

     initial();

     win[0]=newwin(LINES/2-1,COLS-1,0,0);       /* 設定兩個視窗的大小*/
     win[1]=newwin(LINES/2-1,COLS-1,LINES/2,0);

     helpwin=newwin(3,30,2,COLS/2-15 );        /* ONLINE HELP 的大小 */
     box(helpwin,'|','-');
     mvwaddstr(helpwin,0,10,"ONLINE HELP");    /* ONLINE HELP 的內容 */
     mvwaddstr(helpwin,1,4,"Hit any key to continue..");

     for (i=0;i<COLS-1;++i)              /* 畫兩個視窗間的界限 */
       mvaddch(LINES/2-1,i,'-');

     nowwin=0;                          /* 先指定游標在第一視窗 */
     curwin=win[nowwin];
     getyx(curwin,y,x);
     move(0,0);
     refresh();

     refresh();

     do {
       ch=getch();
       switch(ch) {

         case KEY_UP: --y;             /* 判斷是否"↑"鍵被按下       */
                      break;
         case KEY_DOWN: ++y;           /* 判斷是否"↓"鍵被按下       */
                      break;
         case KEY_RIGHT: ++x;          /* 判斷是否"→"鍵被按下       */
                      break;
         case KEY_LEFT: --x;           /* 判斷是否"←"鍵被按下       */
                      break;
         case '\r':                    /* 判斷是否 ENTER 鍵被按下    */
                   ++y;
                   x=0;
                   break;
         case '\t':                    /* 判斷是否 TAB 鍵被按下      */
                   touchwin(helpwin);
                   wrefresh(helpwin);  /* 呼叫 ONLINE HELP */
                   getch();
                   touchwin(win[1-nowwin]);  /* 重畫第一,二視窗 */
                   wrefresh(win[1-nowwin]);
                   touchwin(curwin);
                   wrefresh(curwin);
                   break;
         case 127:                      /* 判斷是否 BACKSPACE 鍵被按下 */
                   wmove(curwin,y,--x);/* delete 一個字元            */
                   waddch(curwin,' ');
                   break;

         case 27 : nowwin=1-nowwin;     /* [ESC] 鍵切換視窗 */
                   curwin=win[nowwin];
                   getyx(curwin,y,x);
                   break;
         default:
                   waddch(curwin,ch);
                   x++;
                   break;
       }
       wmove(curwin,y,x);
       wrefresh(curwin);
     } while(1);
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
