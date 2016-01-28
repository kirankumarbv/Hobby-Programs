
/***************************************************************************


				   SUDOKU
				   ------

*****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>




int a[9][9],m1,m2,op,m,dup[9][9];
char x,diff;

void open()
{	 setcolor(RED) ;
	settextstyle(4,0,8) ;
	outtextxy(100,100,"SU-DO-KU");
	outtextxy(110,150,"-- --  --");
	settextstyle(7,0,3);
	setcolor(GREEN);
	outtextxy(50,300,"Welcome to the game that gives a great feast");
	outtextxy(40,350," to your brain . . ! ! !");
	setcolor(BLUE);
	outtextxy(200,450,"Press Enter key to continue   ");
	getch();
	setcolor(BLACK);
	settextstyle(7,0,3);
	outtextxy(50,300,"Welcome to the game that gives a great feast");
	outtextxy(40,350," to your brain . . ! ! !");
	outtextxy(200,450,"Press Enter key to continue   ");
}

void menu()
{	setcolor(BLACK) ;
	settextstyle(4,0,8) ;
	outtextxy(100,100,"SU-DO-KU");
	outtextxy(110,150,"-- --  --");
	settextstyle(7,0,4);
	setcolor(BLUE);
	outtextxy(220,120,"MAIN MENU");
	outtextxy(220,150," ---- ----");
	setcolor(MAGENTA);
	outtextxy(220,200,"PLAY GAME");
	outtextxy(190,250,"INSTRUCTIONS");
	outtextxy(270,300,"QUIT");
}

int selectmenu()
{ 	if((x==72)&&(m==50||m==100))
	{ 	  setfillstyle(SOLID_FILL,BLACK);
		  bar(50,210+m,150,230+m);
		  bar(500,210+m,600,230+m);
		  m=m-50;
	}
	  if((x==80)&&(m==0||m==50))
	 { 	 setfillstyle(SOLID_FILL,BLACK);
		  bar(50,210+m,150,230+m);
		  bar(500,210+m,600,230+m);
		  m=m+50;
	 }
	setfillstyle(SOLID_FILL,GREEN);
	  bar(50,210+m,150,230+m);
	  bar(500,210+m,600,230+m);
	  return(m);
 }

 void instruct()
 {	 setfillstyle(SOLID_FILL,BLACK);
	 bar(50,260,150,280);
	 bar(500,260,650,280);
	 settextstyle(7,0,4);
	setcolor(BLACK);
	outtextxy(220,120,"MAIN MENU");
	outtextxy(220,150," ---- ----");
	setcolor(BLACK);
	outtextxy(220,200,"PLAY GAME");
	outtextxy(190,250,"INSTRUCTIONS");
	outtextxy(270,300,"QUIT");
	settextstyle(7,0,4) ; setcolor(BLUE);
	outtextxy(190,80,"INSTRUCTIONS");
	outtextxy(195,110,"------------");
	settextstyle(1,0,1) ; setcolor(GREEN);
	outtextxy(100,150,"You will have square boxes which are to be filled");
	outtextxy(30,170,"with the digits from '1' to '9'...");
	outtextxy(40,200,"The rule follows that you cannot change the numbers which are");
	outtextxy(30,220,"already given.");
	outtextxy(40,250,"In the end in every row and every coloumn all the digits from");
	outtextxy(30,270,"'1' to '9' should be present and also in the smaller recoglisable");
	outtextxy(30,290,"squares there should be all the digits from '1' to '9'..");
	outtextxy(250,340,"ALL THE BEST");
	setcolor(BLUE);
	outtextxy(350,400,"Press any key to continue...");
	getch();
	settextstyle(7,0,4) ; setcolor(BLACK);
	outtextxy(190,80,"INSTRUCTIONS");
	outtextxy(195,110,"------------");
	settextstyle(1,0,1) ;
	outtextxy(100,150,"You will have square boxes which are to be filled");
	outtextxy(30,170,"with the digits from '1' to '9'...");
	outtextxy(40,200,"The rule follows that you cannot change the numbers which are");
	outtextxy(30,220,"already given.");
	outtextxy(40,250,"In the end in every row and every coloumn all the digits from");
	outtextxy(30,270,"'1' to '9' should be present and also in the smaller recoglisable");
	outtextxy(30,290,"squares there should be all the digits from '1' to '9'..");
	outtextxy(250,340,"ALL THE BEST");
	outtextxy(350,400,"Press any key to continue...");
}

void difficult()
{	int i;
	setcolor(BLACK) ;
	settextstyle(4,0,8) ;
	outtextxy(100,100,"SU-DO-KU");
	outtextxy(110,150,"-- --  --");
	settextstyle(7,0,4);
	outtextxy(220,120,"MAIN MENU");
	outtextxy(220,150," ---- ----");
	outtextxy(220,200,"PLAY GAME");
	outtextxy(190,250,"INSTRUCTIONS");
	outtextxy(270,300,"QUIT");
	setfillstyle(SOLID_FILL,BLACK);
	 bar(50,210,150,230);
	 bar(500,210,650,230);
	 settextstyle(1,0,0); setcolor(RED);
	 outtextxy(250,30,"SELECT");
	 outtextxy(250,50,"-----");
	 setcolor(BLUE);
	 outtextxy(265,100,"EASY");
	 outtextxy(230,150,"MODERATE");
	 outtextxy(265,200,"HARD");
	  x='a';    m=0;
	 while(x!=13)
	 { 	if((x==72)&&(m==50||m==100))
		 {        setfillstyle(SOLID_FILL,BLACK);
			  bar(50,100+m,150,130+m);
			  bar(500,100+m,600,130+m);
			  m=m-50;
		 }
		  if((x==80)&&(m==0||m==50))
		 { 	 setfillstyle(SOLID_FILL,BLACK);
			  bar(50,100+m,150,130+m);
			  bar(500,100+m,600,130+m);
			  m=m+50;
		 }
		   setfillstyle(SOLID_FILL,GREEN);
		  bar(50,100+m,150,130+m);
		  bar(500,100+m,600,130+m);
		  fflush(stdin);
		  x=getche();
	 }
	 settextstyle(1,0,0); setcolor(BLACK);
	 outtextxy(250,30,"SELECT");
	 outtextxy(250,50,"-----");
	 outtextxy(265,100,"EASY");
	 outtextxy(230,150,"MODERATE");
	 outtextxy(265,200,"HARD");
	 setfillstyle(SOLID_FILL,BLACK);
	  bar(50,100+m,150,130+m);
	  bar(500,100+m,600,130+m);
}

 void load()
 {	 int i,j;
	 settextstyle(1,0,0);setcolor(RED);
	 outtextxy((getmaxx()/2)-55,(getmaxy()/2)-50,"LOADING");
	 rectangle(getmaxx()/2-100,getmaxy()/2-10,getmaxx()/2+100,getmaxy()/2+10);
	 for(i=0;i<170;i++)
	 {  	setfillstyle(SOLID_FILL,BLUE);
		 bar(getmaxx()/2-90+i,getmaxy()/2- 5,getmaxx()/2-80+i,getmaxy()/2+5);
		 delay(50);
	 }
	 setfillstyle(SOLID_FILL,BLACK) ;
	 bar(getmaxx()/2-90,getmaxy()/2-5,getmaxx()/2-80+i-1,getmaxy()/2+5);
	 settextstyle(1,0,0);
	 setcolor(BLACK);
	 outtextxy((getmaxx()/2)-55,(getmaxy()/2)-50,"LOADING");
	 rectangle(getmaxx()/2-100,getmaxy()/2-10,getmaxx()/2+100,getmaxy()/2+10);  settextstyle(4,0,8) ;  setcolor(BLUE);
 }

void game()
{	 int i;
	 outtextxy(100,5,"SU-DO-KU");
	 outtextxy(102,40,"-- --  --");
	 setcolor(GREEN);
	 rectangle(50,110,410,470);
	 for(i=40;i<360;i=i+40)
	 {	setcolor(RED);
		 if(i%120==0)
		 { 	 setcolor(GREEN);
			 line(50+i+1,110,50+i+1,470);
			 line(50,110+i+1,410,110+i+1);
			 line(50+i-1,110,50+i-1,470);
			 line(50,110+i-1,410,110+i-1);
		 }
		 line(50+i,110,50+i,470);
		 line(50,110+i,410,110+i);
	 }
}

 void store()
 { 	 int i,j,k,n,o,flag,r;
	  for(i=0;i<9;i++)
	 { 	for(j=0;j<9;j++)
		 a[i][j]=0;
	 }
	 if(m==0)
	 {	diff='e';
		 a[1][0]=9;  a[4][0]=5;   a[7][0]=2;  a[8][0]=1;
		 a[0][1]=5;  a[2][1]=3;   a[5][1]=7;  a[7][1]=9;   a[8][1]=8;
		 a[1][2]=2;  a[3][2]=4;   a[5][2]=8;
		 a[0][3]=6;  a[5][3]=4;   a[7][3]=5;   a[8][3]=9;
		 a[2][4]=5;  a[6][4]=8;
		 a[0][5]=4;  a[1][5]=7;   a[2][5]=9;  a[3][5]=3;   a[8][5]=2;
		 a[3][6]=5;  a[5][6]=1;   a[7][6]=8;
		 a[0][7]=7;  a[1][7]=5;   a[3][7]=8;  a[5][7]=9;  a[6][7]=6;  a[8][7]=3;
		 a[0][8]=3;  a[1][8]=1;   a[4][8]=6;  a[7][8]=4;  }

	 if(m==50)
	{ 	 diff='m';
		 a[1][0]=3;  a[2][0]=6;  a[4][0]=7;  a[6][0]=2;
		 a[0][1]=4;  a[3][1]=8;  a[4][1]=9;  a[8][1]=6;
		 a[5][2]=4;
		 a[1][3]=5;  a[2][3]=7;  a[6][3]=9;  a[7][3]=3;
		 a[1][5]=8;  a[7][5]=5;
		 a[3][6]=3;
		 a[0][7]=2;  a[4][7]=8;  a[5][7]=7;  a[8][7]=3;
		 a[2][8]=9;  a[4][8]=2;  a[6][8]=4;  a[7][8]=8;}

	 if(m==100)
	{	 diff='h';
		 a[0][0]=8;  a[3][0]=6;  a[4][0]=2;  a[8][0]=9;
		 a[0][1]=9;
		 a[1][2]=4;  a[3][2]=9;  a[7][2]=5;  a[8][2]=2;
		 a[2][3]=3;  a[3][3]=8;  a[4][3]=4;  a[8][3]=7;
		 a[3][4]=2;  a[5][4]=1;
		 a[0][5]=7;  a[4][5]=3;  a[5][5]=6;  a[6][5]=1;
		 a[0][6]=2;  a[1][6]=9;  a[5][6]=3;  a[7][6]=8;
		 a[8][7]=4;
		 a[0][8]=1;  a[4][8]=8;  a[5][8]=5;  a[8][8]=3;}
	  for(i=0;i<9;i++)
	  {	  for(j=0;j<9;j++)
		  dup[i][j]=a[i][j];
	  }
  }


  void numbers()
 {	 int i,j;
	 char ch[1];
	 settextstyle(1,0,0); setcolor(WHITE);
	 for(i=0;i<9;i++)
	 for(j=0;j<9;j++)
	 {	 sprintf(ch,"%d",a[i][j]);
		 if(a[i][j]!=0)
		 outtextxy(60+(i*40),110+(j*40),ch );
	 }
 }


 void controls()
{	 setcolor(YELLOW);
	rectangle(450,110,630,400);
	setcolor(MAGENTA); settextstyle(1,0,0);
	outtextxy(460,115,"CONTROLS");
	outtextxy(460,130,"-------");
	settextstyle(1,0,1);    setcolor(CYAN);
	outtextxy(455,280,"To erase a number ");
	outtextxy(460,300,"go to the place ");
	outtextxy(460,320,"and press \"SPACE\"") ;
	outtextxy(460,350,"Press 'ESC' to exit");
}

void actual()
{	char ch[1],an; int a1,a2,flag;
	x='p';
	while(x!=27)
	{	x=getche();
		if((x==72)&&m2>0)
		{	setcolor(BLACK) ;
			rectangle(52+m1,112+m2,88+m1,148+m2);
			m2=m2-40;
			setcolor(YELLOW);
			rectangle(52+m1,112+m2,88+m1,148+m2);
		}
		if((x==80)&&m2<320)
		{ 	 setcolor(BLACK) ;
			 rectangle(52+m1,112+m2,88+m1,148+m2);
			 m2=m2+40;
			 setcolor(YELLOW);
			 rectangle(52+m1,112+m2,88+m1,148+m2);
		}
		 if((x==77)&&m1<320)
		{	 setcolor(BLACK) ;
			 rectangle(52+m1,112+m2,88+m1,148+m2);
			 m1=m1+40;
			 setcolor(YELLOW);
			 rectangle(52+m1,112+m2,88+m1,148+m2);
		}
		 if((x==75)&&m1>0)
		{ 	setcolor(BLACK) ;
			 rectangle(52+m1,112+m2,88+m1,148+m2);
			 m1=m1-40;
			 setcolor(YELLOW);
			 rectangle(52+m1,112+m2,88+m1,148+m2);
		}
		 if((x>'0'&&x<='9')&&a[m1/40][m2/40]==0)
		 {	a[m1/40][m2/40]=x-48;   setcolor(CYAN);
			 sprintf(ch,"%d",a[m1/40][m2/40]);
			 outtextxy(60+m1,110+m2,ch);
		 }
		 if(x==' ' )
		 {	 a1=m1/40;  a2=m2/40;
			if(dup[a1][a2]==0)
			   {	     setcolor(BLACK)  ;
				     sprintf(ch,"%d",a[a1][a2]);
				     outtextxy(60+m1,110+m2,ch);
				     a[a1][a2]=0;
			   }
		  }
		  flag=0;
		  for(a1=0;a1<9;a1++)
		  for(a2=0;a2<9;a2++)
		  { 	if(a[a1][a2]==0)
			{	 flag=1;
				break;
			}
		  }

		if(flag==0)
		  break;
	  }
 }


int check()
 {	int i,j,check=0;
	  for(i=0;i<9;i++)
	  {	for(j=0;j<9;j++)
		{	if(a[i][j]==0)
			{	check=1;
				 break;
			}
		 }
	   }
	 if(check==1)
	 return 1;
	 else
	 return 0 ;
 }



void luck()
{	 settextstyle(7,0,4);  setcolor(GREEN);
	outtextxy(250,120,"GAME OVER");   setcolor(RED);
	outtextxy(30,250,"You Didn't even complete the game");
	outtextxy(100,400,"ALL THE BEST NEXT TIME");
}

int over()
{	int count,i,j,k,l;
	for(k=1;k<10;k++)
	{	 count=-1;
		for(i=0;i<9;i++)
		{	count=-1;
			for(j=0;j<9;j++)
			{	 if(a[i][j]==k)
				 count++;
			}
			if(count>0)
			return count;
		}

		count=-1;
		for(i=0;i<9;i++)
		{	count=-1;
			for(j=0;j<9;j++)
			{
				if(a[j][i]==k)
				count++;
			}
		  if(count>0)
		  return count;
		 }

		count=-1;
		for(i=0;i<3;i++)
		{	for(j=0;j<3;j++)
			{	if(a[i][j]==k)
				 count++;
			}
			if(count>0)
			return count;
		}

		count=-1;
		for(i=3;i<6;i++)
		{	for(j=3;j<6;j++)
			{	if(a[i][j]==k)
				count++;
			}
			if(count>0)
			return count;
		}


		count=-1;
		for(i=6;i<9;i++)
		{	for(j=6;j<9;j++)
			{	if(a[i][j]==k)
				count++;
			}
			if(count>0)
			return count;
		}
	}
	return 0;
}

void wrong()
{	 setcolor(RED);
	settextstyle(7,0,4);
	outtextxy(250,120,"GAME OVER"); setcolor(GREEN);
	outtextxy(10,200,"THERE WERE MISTAKES IN YOUR");
	outtextxy(10,260,"SOLVED PUZZLE SO TRY AGAIN");
}

void right()
{	 setcolor(RED);
	 settextstyle(7,0,4);
	outtextxy(250,120,"CONGRATS"); setcolor(GREEN);
	outtextxy(50,200,"YOU HAVE EXCELLED IN ");
	outtextxy(50,260,"COMPLETING THE PUZZLE");
}



void main()

{	 int g=DETECT,m,val;
	clrscr();
	initgraph(&g,&m,"d:\\tcarvind\\bgi");
	open();
	start :
	menu();
	m=0;
	 x='a';
	while(x!=13)
	{	op=selectmenu();
		fflush(stdin);
		x=getche();
	}
	if(op==100)
	exit(0);
	if(op==50)
	{	 instruct();
		goto start;
	}
	if(op==0)
	{	x='p';
		difficult();
		store();
		load();
		game();
		controls();
		numbers();
		setcolor(YELLOW);
		rectangle(52,112,88,148);  m1=0; m2=0 ;
		actual();
		val=check();
		setfillstyle(SOLID_FILL,BLACK);
		bar(10,110,700,700);
		if(val==1)
		luck();
		else
		{ 	if(val==0)
			val=over();
			if(val!=0)
			wrong();
			else right();
		}
		getch();
		setfillstyle(SOLID_FILL,BLACK);
		bar(0,0,700,700);
		settextstyle(1,0,0);
		setcolor(GREEN);
		outtextxy(230,200,"PLAY AGAIN");
		setcolor(RED);
		outtextxy(280,250,"YES");
		outtextxy(290,300,"NO");

		setfillstyle(SOLID_FILL,BLUE);
		m=0;
		bar(180,260+m,250,280+m);
		bar(380,260+m,450,280+m);
		 do
		 {	x=getche();
			 if((x==80)&&m==0)
			 {	  setfillstyle(SOLID_FILL,BLACK);
				    bar(180,260+m,250,280+m);
				    bar(358,260+m,450,280+m);
				    m=m+50;
				    setfillstyle(SOLID_FILL,BLUE);
				    bar(180,260+m,250,280+m);
				    bar(380,260+m,450,280+m);
			 }
			 if((x==72)&&m==50)
			  {	  setfillstyle(SOLID_FILL,BLACK);
				bar(180,260+m,250,280+m);
				 bar(380,260+m,450,280+m);
				    m=m-50;
				    setfillstyle(SOLID_FILL,BLUE);
				    bar(180,260+m,250,280+m);
				    bar(380,260+m,450,280+m);
			 }
		 } while(x!=13);
		 if(m==0)
		 {	setfillstyle(SOLID_FILL,BLACK);
			 bar(0,0,700,700);
			 goto start;
		 }
		 else
		 exit(0);


	}

}




