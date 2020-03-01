#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <iostream>

using namespace std;

int fx=2450,fy=1250,sx=50,sy=50,w=15,c;
int mx=(fx)/w;
int my=(fy)/w;

void draw_matrix(int x,int y,int w){
	setcolor(BLUE);
	for(int i=0;i<=x;i++)
		line(sx+w*i,sy,sx+w*i,sy+w*y);
	for(int i=0;i<=y;i++)
		line(sx,sy+w*i,sx+w*x,sy+w*i);
}

main(){
	initwindow(fx+100,fy+100);
	draw_matrix(mx,my,w);
	bool mat[mx][my]={0};
	int dir=0,x=mx/2,y=my/2;
	while(y<my){
		setfillstyle(SOLID_FILL,RED);
		floodfill(sx+w*x+1,sy+w*y+1,BLUE);
		_sleep(10);
		if(!mat[x][y]){
			dir=(dir+1)%4;
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(sx+w*x+1,sy+w*y+1,BLUE);
			mat[x][y]=true;
		}
		else{
			dir=((dir+4-1)%4);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(sx+w*x+1,sy+w*y+1,BLUE);
			mat[x][y]=false;
		}
		if(dir==0) y--;
		else if(dir==1) x++;
		else if(dir==2) y++;
		else if(dir==3) x--;
	}
	getch();
	closegraph();
}
