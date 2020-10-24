#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void food();
void show();
void move();
void turn();
void check();
void ini();
int  dy[4] = { 0, 1, 0, -1 };
int  dx[4] = { -1, 0, 1, 0 };
int sum = 5;  //���ܳ���
int over = 0;
int speed = 50;	//ԽСԽ��    
char map[20][80];

void hide(){	//���ع�� 
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO CursorInfo;
GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
CursorInfo.bVisible = false; //���ؿ���̨���
SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬

}

struct snake {
    int x, y;  //�������� 
    int dir;  //����
} A[100];

void ini() {  //��ʼ������
    over = 0;
    sum = 5;
    int i, j;
    for (i = 0; i < 80; i++) {  //��ʼ����ͷ�����������
        A[i].dir = 0;
        A[i].x = 0;
        A[i].y = 0;
    }
    A[0].x = 1; A[0].y = 1;  
    A[1].x = 1; A[1].y = 2;
    A[2].x = 1; A[2].y = 3;
    A[3].x = 1; A[3].y = 4;
    A[4].x = 1; A[4].y = 5; A[4].dir = 1;
    srand(time(0));
    for (i = 0; i < 20; i++) {  //���õ�ͼ
        for (j = 0; j < 80; j++) {
            map[i][j] = '*';
        }
    }
    for (i = 1; i < 19; i++) {
        for (j = 1; j <79; j++) {
            map[i][j] = ' ';
        }
    }
map[6][14]='*';map[6][22]='*';
map[7][13]='*';map[7][15]='*';map[7][21]='*';map[7][23]='*';
map[8][12]='*';map[8][16]='*';map[8][20]='*';map[8][24]='*';
map[9][11]='*';map[9][17]='*';map[9][19]='*';map[9][25]='*';
map[10][10]='*';map[10][18]='*';map[10][26]='*';//M 

map[6][33]='*';map[6][34]='*';map[6][35]='*';
map[7][30]='*';map[7][31]='*';map[7][32]='*';map[7][36]='*';map[7][37]='*';map[7][38]='*';
map[8][33]='*';map[8][34]='*';map[8][35]='*';
map[9][30]='*';map[9][31]='*';map[9][32]='*';map[9][36];map[9][37]='*';map[9][38]='*';
map[10][33]='*';map[10][34]='*';map[10][35]='*';//S

map[6][45]='*';map[6][46]='*';map[6][47]='*';map[6][48]='*';
map[7][43]='*';map[7][44]='*';map[7][49]='*';map[7][50]='*';
map[8][43]='*';map[8][44]='*';
map[9][43]='*';map[9][44]='*';map[9][49]='*';map[9][50]='*';
map[10][45]='*';map[10][46]='*';map[10][47]='*';map[10][48]='*';//C



    map[A[4].x][A[4].y] = 'M';  //������ͷ
    for (i = 0; i < sum - 1; i++) {  //��������
        map[A[i].x][A[i].y] = 'S';
    }
    food();
}


void show() {  //��ʾ���� 
    int i, j, x, y;
    for (i = 0; i < 20; i++) {  //��ʾ����
        for (j = 0; j < 80; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    while (1) {
        Sleep(speed);  //����ˢ���ٶ�
        turn();
        move();
        if (over) {  //��������������Խ��еĲ��� 
            while (1) {
                char ch = _getch();
                if (ch == 113) {  //���롮q������ 
                    return;
                }
                else if (ch == 114) {  //���롮r�����¿�ʼ 
                    ini();
                    break;
                }
            }
        }
        system("cls");  //���� 
        for (i = 0; i <20; i++) {  //������ʾ����
            for (j = 0; j < 80; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
}

void food() {  //����ʳ��
    int x, y;
    while (1) {
        x = (int)(15 * rand() / (RAND_MAX + 1.0));  //�������һ��ʳ������
        y = (int)(78 * rand() / (RAND_MAX + 1.0));
        if (map[x][y] == ' ') {  //����ǿո����ڸô�����ʳ��
            map[x][y] = 'C';
            break;
        }
    }
}


void move() {  //���ƶ� 
    int i, x, y;
    int t = sum;  //��¼��ǰ���ܳ��� 
    check();  //�ƶ�ǰ��鰴��ǰ�����ƶ�һ��������
    if (t == sum) {  //û�гԵ�ƻ��
        for (i = 0; i < sum - 1; i++) {
            if (i == 0) {  //��β���괦��ɿո񣬰���β������ǰһ����������� 
                map[A[i].x][A[i].y] = ' ';
                A[i].x = A[i + 1].x;
                A[i].y = A[i + 1].y;
            }
            else {  //ÿ���������궼��Ϊ��ǰһ�����������
                A[i].x = A[i + 1].x;
                A[i].y = A[i + 1].y;
            }
            map[A[i].x][A[i].y] = 'S';  //�ѵ�ͼ���������괦���ַ����óɡ�S��
        }
        A[sum - 1].x = A[sum - 1].x + dx[A[sum - 1].dir];  //��ͷ����ǰ�����ƶ�һ�� 
        A[sum - 1].y = A[sum - 1].y + dy[A[sum - 1].dir];
        map[A[sum - 1].x][A[sum - 1].y] = 'M';  //�ѵ�ͼ����ͷ���괦���ַ����óɡ�M��
    }
    else {  //�Ե�ƻ��
        map[A[sum - 2].x][A[sum - 2].y] = 'S';  //�ѵ�ͼ��ԭ��ͷ���괦���ַ����óɡ�S��
        A[sum - 1].x = A[sum - 2].x + dx[A[sum - 2].dir];  //����ͷ��������ԭ��ͷ�ص�ǰ�����ƶ�һ�������� 
        A[sum - 1].y = A[sum - 2].y + dy[A[sum - 2].dir];
        A[sum - 1].dir = A[sum - 2].dir;  //����ͷ����Ϊԭ��ͷ�ķ���
        map[A[sum - 1].x][A[sum - 1].y] = 'M';  //�ѵ�ͼ����ͷ���괦���ַ����óɡ�M��
        food();
    }
}

void check() {  //����Ƿ��������߳Ե�ʳ��
    int x, y, i, j;
    x = A[sum - 1].x + dx[A[sum - 1].dir];  //��¼����ǰ�����ƶ�һ�����ͷ������ 
    y = A[sum - 1].y + dy[A[sum - 1].dir];
    if (map[x][y] == '*' || map[x][y] == 'S') {  //�����ͼ�ϸ����괦�ַ�Ϊ��*����S�������� 
        if (x != A[0].x || y != A[0].y) {  //��β���� 
            map[8][4] = 'G'; map[8][5] = 'A'; map[8][6] = 'M'; map[8][7] = 'E';  //�����GAME OVER�� 
            map[8][9] = 'O'; map[8][10] = 'V'; map[8][11] = 'E'; map[8][12] = 'R';
            map[8][8] = ' ';
            system("cls");
            for (i = 0; i < 20; i++) {
                for (j = 0; j < 80; j++) {
                    printf("%c", map[i][j]);
                }
                printf("\n");
            }
            printf("����r�����¿�ʼ\n����q���˳���Ϸ\n");
            printf("����������治���ˣ�");
            over = 1;
        }   
    }
    else if(map[x][y]=='C')
	sum++;
}

void turn() {  //ת��
    if (_kbhit()) {
        char dir = _getch();  //��ȡ����ļ� 
        switch (dir) {  //�ı䷽�� 
        case 119: A[sum - 1].dir = (A[sum - 1].dir == 2)?2:0; break;
        case 100: A[sum - 1].dir = (A[sum - 1].dir == 3)?3:1; break;
        case 115: A[sum - 1].dir = (A[sum - 1].dir == 0)?0:2; break;
        case 97: A[sum - 1].dir = (A[sum - 1].dir == 1)?1:3; break;
        }
    }
}


int main() {
    printf("'w''s''a''d'������������\n���������ʼ\n�����\nDont_fishing\n");
    hide(); 
	char ch = _getch();
    system("cls");
    ini();
    show(); 
    return 0;
}

