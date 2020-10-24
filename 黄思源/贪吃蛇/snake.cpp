#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>
 #include<iostream>
#define X 23//地图的x轴
#define Y 75//地图的y轴
 
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
 
//等待蛇刷新的时间,可以说是速度  修改可变速
 
int map_0[X][Y],msc[3][2];//地图
int Snake[X*Y][2]; // 蛇
int Slength; //蛇的长度
int direction;
int score=0;
 
bool pdEatFood=false;
 
void csh();
void huaMap();
void huaSnake();
void gotoxy(int x,int y);
void move();
void intokey();
int check(int x,int y);
void putfood();
bool gameover();
void dy_fs();
 int h[6]={0,10,12,14,16,20};
int main() {
	int WAIT_TIME,level;
    gotoxy(0,0);printf("Chose a level (1~5)");
    gotoxy(1,0);std::cin>>level;
    csh();
    huaMap();
    putfood();
    int x=rand()%X/3,y=rand()%Y/3;
    msc[0][0]=x,msc[0][1]=y;map_0[x][y]=-2;
    gotoxy(x,y);printf("M");
	x=rand()%X/3+X/3,y=rand()%Y/3+Y/3;
    msc[1][0]=x,msc[1][1]=y;map_0[x][y]=-2;
    gotoxy(x,y);printf("S");
	x=rand()%X/3+X/3+X/3,y=rand()%Y/3+Y/3+Y/3;
    msc[2][0]=x,msc[2][1]=y;map_0[x][y]=-2;
    gotoxy(x,y);printf("C");
	Sleep(2000);
    switch(level){
    	case 1:WAIT_TIME=180;break;
    	case 2:WAIT_TIME=150;break;
    	case 3:WAIT_TIME=120;break;
    	case 4:WAIT_TIME=90;break;
    	case 5:WAIT_TIME=60;break;
	}
    while(1) {
        huaSnake();
        Sleep(WAIT_TIME);
        intokey();
        move();
        dy_fs();
        if(gameover()) {
            system("cls");          //清除屏幕内容
            printf("Game Over\n\nYour score: %d\n\nPress any two keys to exit.",score);
            getch();getch();
            break;
        }
        if(map_0[Snake[0][0]][Snake[0][1]]==-1) {
            map_0[Snake[0][0]][Snake[0][1]]=0;
            pdEatFood=true;
            int many=rand()%10;
            putfood();
            if(!many)putfood();
            score+=h[level];
        }
    }
    return 0;
}
void csh() { //初始化
    srand((unsigned)time(NULL)); //设置种子为现在的时间
    Slength=4;
    gotoxy(0,0);
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; //清除光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    int x,y;
    Snake[0][0]=X/2;
    Snake[0][1]=Y/2;
    for(x=0; x<X; x++) {
        map_0[x][0]=1;
        map_0[x][Y-1]=1;
    }
    for(y=0; y<Y-1; y++) {
        map_0[0][y]=1;
        map_0[X-1][y]=1;
    }
    for(x=1; x<4; x++) { //初始化蛇的坐标
        Snake[x][0]=Snake[0][0]+x;
        Snake[x][1]=Snake[0][1];
    }
    direction=UP;
 
}
void huaMap() { //画地图
    int x,y;
    for(x=0; x<X; x++) {
        for(y=0; y<Y; y++) {
            if(map_0[x][y]==1)printf("#");
            if(map_0[x][y]==0)printf(" ");
		}
        printf("\n");
    }
}
void huaSnake() { //画蛇
    int x;
    gotoxy(Snake[0][0],Snake[0][1]);
    printf("@");
    for(x=1; x<Slength; x++) {
        gotoxy(Snake[x][0],Snake[x][1]);
        printf("o");  
    }
}
void gotoxy(int i,int j) { //移动光标
    COORD position= {j,i};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}
void move() {
    int i;
    gotoxy(Snake[Slength-1][0],Snake[Slength-1][1]);//擦除尾巴
    printf(" ");
    for(i=Slength-1; i>0; i--) { //从尾巴开始，每一个点的位置等于它前面一个点的位置
        Snake[i][0]=Snake[i-1][0];
        Snake[i][1]=Snake[i-1][1];
    }
    switch(direction) {
        case UP:
            Snake[0][0]--;
            break;
        case DOWN:
            Snake[0][0]++;
            break;
        case LEFT:
            Snake[0][1]--;
            break;
        case RIGHT:
            Snake[0][1]++;
            break;
    }
    if(pdEatFood) {
        Slength++;
        pdEatFood=false;
    }
 
}
void intokey() {
    if(kbhit()!=0) {        //kbhit()函数 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
        char in;
        while(!kbhit()==0)  //如果玩家输入了多个按键，以最后一个按键为准
            in=getch();
        switch(in) {
            case 'w':
            case 'W':
                if(direction!=DOWN)         //防止缩头
                    direction=UP;
                break;
            case 's':
            case 'S':
                if(direction!=UP)
                    direction=DOWN;
                break;
            case 'a':
            case 'A':
                if(direction!=RIGHT)
                    direction=LEFT;
                break;
            case 'd':
            case 'D':
                if(direction!=LEFT)
                    direction=RIGHT;
                break;
            case 'p':
            case 'P':
                gotoxy(X,0);
                system("pause");
                gotoxy(X,0);
                printf("                   ");  //  消去下面的按任意键继续
                break;
            case ' ':exit(0);break;
        }
    }
}
int check(int ii,int jj){ // 检查是否能投放食物
    if(map_0[ii][jj]==1)return 0;
    if(ii==0 || jj==0 || ii==X-1 || jj==Y-1)return 0;
    int i;
    for(i=0; i<Slength; i++) {
        if(ii==Snake[i][0] && jj==Snake[i][1])return 0;
    }
    return 1;
}
void putfood() {
    int i,j;
    do {
        i=rand()%X;
        j=rand()%Y;
    } while(!check(i,j));
    map_0[i][j]=-1;
    gotoxy(i,j);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
    printf("+");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
}
bool gameover() {
    bool isgameover=false;
    int sX,sY;
    sX=Snake[0][0],sY=Snake[0][1];
    if(sX==0 || sX==X-1 || sY==0 || sY==Y-1)isgameover=1;
    for(int i=0;i<3;i++)if(sX==msc[i][0]&&sY==msc[i][1])isgameover=1;
    int i;
    for(i=1; i<Slength; i++) {
        if(sX==Snake[i][0] && sY==Snake[i][1])isgameover=1;
    }
    return isgameover;
}
void dy_fs() {
    gotoxy(X,0);
    printf("Copy from http://yuncode.net/code/c_5cc2dd9e9c31461");
    gotoxy(X+2,0);
    printf("******  Modified and debuged by dowr for MSC new member test  ******\n\n");
    gotoxy(X+4,0);
    printf("Score: %d",score);
    gotoxy(X+7,0);
    printf("Tip : (There is a chance to add an apple when you eat one and you can't touch MSC.)");
    gotoxy(X+6,0);
    printf("Press WASD to move, P to pause, blank to exit.");
}
