#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include <iomanip>
#include <windows.h>
using namespace std;
int mp[4][4],score;
bool map[4][4];
bool cal[4][4];
void print()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
    for(int j=0;j<4;++j)printf("----");
    printf("\n");
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            printf("|");
            if(map[i][j]){
                if(mp[i][j]==2)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
                if(mp[i][j]==4)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
                if(mp[i][j]==8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
                if(mp[i][j]==16)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
                if(mp[i][j]==32)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
                if(mp[i][j]==64)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
                if(mp[i][j]==128)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0d);
                if(mp[i][j]==256)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
                if(mp[i][j]==512)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7d);
                if(mp[i][j]==1024)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
                printf("%3d",mp[i][j]);
            }else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0),printf("   ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
        printf("|\n");
        for(int j=0;j<4;++j)printf("----");
        printf("\n");
    }
    printf("w : up  s : down  a : left  d : right\n");
    printf("push 'r' to start a new game\npush 'e' to exit game\n\n");
    printf("Copy from https://blog.csdn.net/qq_41020768/article/details/78782884\n\n");
    printf("******  Modified by dowr for MSC new member test  ******\n\n");

}
void MoveUp()
{
    bool flag;
    for(int j=0;j<4;j++){
        for(int i=1;i<4;i++){
            if(!map[i][j])continue;
            flag=0;
            int pos=i;
            for(int k=i-1;k>=0;--k){
                if(!map[k][j]){pos=k;continue;}
                if(mp[k][j]==mp[i][j]){
                    mp[k][j]+=mp[i][j];score+=mp[k][j];
                    flag=true;
                    map[i][j]=false;break;
                }
                else break;
            }
            if(!flag){
                mp[pos][j]=mp[i][j];
                map[i][j]=false;
                map[pos][j]=true;
            }
        }
    }
}
void MoveDown()
{
    bool flag;
    for(int j=0;j<4;j++){
        for(int i=2;i>=0;i--){
            if(!map[i][j])continue;
            flag=false;
            int pos=i;
            for(int k=i+1;k<4;++k){
                if(!map[k][j]){
                    pos=k;
                    continue;
                }
                if(mp[k][j]==mp[i][j]){
                    mp[k][j]+=mp[i][j];score+=mp[k][j];
                    flag=true;
                    map[i][j]=false;break;
                }
                else
                    break;
            }
            if(!flag){
                mp[pos][j]=mp[i][j];
                map[i][j]=false;
                map[pos][j]=true;
            }
        }
    }
}
void MoveRight()
{
    bool flag;
    for(int i=0;i<4;++i){
        for(int j=2;j>=0;j--){
            if(!map[i][j])continue;
            flag=0;
            int pos=j;
            for(int k=j+1;k<4;++k){
                if(!map[i][k]){
                    pos=k;
                    continue;
                }
                if((mp[i][k]==mp[i][j])){
                    mp[i][k]+=mp[i][j];score+=mp[i][k];
                    flag=true;
                    map[i][j]=false;break;
                }
                else
                    break;
            }
            if(!flag){
                mp[i][pos]=mp[i][j];
                map[i][j]=0;
                map[i][pos]=1;
            }
        }
    }
}
void MoveLeft()
{
    bool flag;
    for(int i=0;i<4;++i){
        for(int j=1;j<4;j++){
            if(!map[i][j])continue;
            flag=0;
            int pos=j;
            for(int k=j-1;k>=0;--k){
                if(!map[i][k]){
                    pos=k;
                    continue;
                }
                if(mp[i][k]==mp[i][j]){
                    mp[i][k]+=mp[i][j];score+=mp[i][k];
                    flag=true;
                    map[i][j]=0;break;
                }
                else break;
            }
            if(!flag){
                mp[i][pos]=mp[i][j];
                map[i][j]=0;
                map[i][pos]=1;
            }
        }
    }
}
void Init()
{
    srand(time(NULL));
    int x,y,v,now=0;
    for(int i=0;i<4;++i)
    for(int j=0;j<4;++j)
        if(!map[i][j])now++;
    if(now==0)return;
    int cnt=rand()%now,n=0;
    bool flag=false;
    for(int i=0;i<4;++i){
        flag=false;
        for(int j=0;j<4;++j)
        if(!map[i][j]){
            if(cnt==n){
                x=i;y=j;
                flag=true;
                break;
            }
            else n++;
        }
        if(flag)break;
    }
    v=rand()%2;
    if(v)v=4;
    else v=2;
    mp[x][y]=v;
    map[x][y]=true;
}
bool gameover()
{
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(!map[i][j])return 0;
            if(i>0){
                if(mp[i-1][j]==mp[i][j])return false;
            }
            if(j>0)
                if(mp[i][j-1]==mp[i][j])
                    return false;
        }
    }
    return true;
}
void Lose()
{
    char ch;
    system("cls");
    printf("*******************\n");
    printf("**** GAME OVER ****\n");
    printf("**** SCORE:%3d ****\n",score);
    printf("*******************\n\n");
    printf("Push any button to continue\n");
    ch=getch();
    return ;
}
void gotoxy(int i,int j) { //移动光标
    COORD position= {j,i};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}
void Win()
{
    char ch;
    system("cls");
    printf("*******************\n");
    printf("**** YOU  WIN! ****\n");
    printf("*******************\n\n");
    printf("Push any button to continue\n");
    ch=getch();
    return ;
}
void start()
{
    system("cls");
    printf("********************\n");
    printf("* game start glhf~ *\n");
    printf("********************\n");
    int x=5e8;
    bool flag=false;
    while(x--);
    memset(mp,0,sizeof(mp));
    memset(map,false,sizeof(map));
    score=0;
    char ch;
    while(!gameover())
    {
        memset(cal,false,sizeof(cal));
        int cnt=0;
        system("cls");
        Init();
        print();
        gotoxy(3,20);
        printf("Score: %d\n",score);
        gotoxy(0,0);
       // DeBug();
        ch=getch();
        switch (ch)
        {
            case 'w':MoveUp();MoveUp();MoveUp();break;
            case 's':MoveDown();MoveDown();MoveDown();break;
            case 'a':MoveLeft();MoveLeft();MoveLeft();break;
            case 'd':MoveRight();MoveRight();MoveRight();break;
            case 'e':exit(0);
            case 'r':return ;
        }
        if(score>=2048){
            flag=true;
            break;
        }
    }
    if(flag)Win();
    else Lose();
    return ;
}
 
int main()
{
	//system("title yourname");
    char ch;
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; //清除光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    while(1)
    {
        system("cls");
        printf("Copy from https://blog.csdn.net/qq_41020768/article/details/78782884\n\n");
        printf("******  Modified and debuged by dowr for MSC new member test  ******\n\n");
        printf("ENTER to start game\nESC to exit\n");
        ch=getch();
        if(ch==13)
            start();
        else if(ch==27)
            break;
    }
    return 0;
}
