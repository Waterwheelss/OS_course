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

     win[0]=newwin(LINES/2-1,COLS-1,0,0);       /* �]�w��ӵ������j�p*/
     win[1]=newwin(LINES/2-1,COLS-1,LINES/2,0);

     helpwin=newwin(3,30,2,COLS/2-15 );        /* ONLINE HELP ���j�p */
     box(helpwin,'|','-');
     mvwaddstr(helpwin,0,10,"ONLINE HELP");    /* ONLINE HELP �����e */
     mvwaddstr(helpwin,1,4,"Hit any key to continue..");

     for (i=0;i<COLS-1;++i)              /* �e��ӵ��������ɭ� */
       mvaddch(LINES/2-1,i,'-');

     nowwin=0;                          /* �����w��Цb�Ĥ@���� */
     curwin=win[nowwin];
     getyx(curwin,y,x);
     move(0,0);
     refresh();

     refresh();

     do {
       ch=getch();
       switch(ch) {

         case KEY_UP: --y;             /* �P�_�O�_"��"��Q���U       */
                      break;
         case KEY_DOWN: ++y;           /* �P�_�O�_"��"��Q���U       */
                      break;
         case KEY_RIGHT: ++x;          /* �P�_�O�_"��"��Q���U       */
                      break;
         case KEY_LEFT: --x;           /* �P�_�O�_"��"��Q���U       */
                      break;
         case '\r':                    /* �P�_�O�_ ENTER ��Q���U    */
                   ++y;
                   x=0;
                   break;
         case '\t':                    /* �P�_�O�_ TAB ��Q���U      */
                   touchwin(helpwin);
                   wrefresh(helpwin);  /* �I�s ONLINE HELP */
                   getch();
                   touchwin(win[1-nowwin]);  /* ���e�Ĥ@,�G���� */
                   wrefresh(win[1-nowwin]);
                   touchwin(curwin);
                   wrefresh(curwin);
                   break;
         case 127:                      /* �P�_�O�_ BACKSPACE ��Q���U */
                   wmove(curwin,y,--x);/* delete �@�Ӧr��            */
                   waddch(curwin,' ');
                   break;

         case 27 : nowwin=1-nowwin;     /* [ESC] ��������� */
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
