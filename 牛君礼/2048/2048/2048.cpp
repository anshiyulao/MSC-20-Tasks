#define _CRT_SECURE_NO_WARNINGS
#include <easyx.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
IMAGE img[12];
int imgIndex[12] = {0,2,4,8,16,32,64,128,256,512,1024,2048 };
int i, j;
int map[4][4] = { 0 };
void loadResource()
{
	for (i = 0; i < 12; i++)
	{
		char fileName[20] = "";
		sprintf(fileName, "%d.bmp", imgIndex[i]);
		loadimage(img + i, fileName);
	}
}
void drawMap()
{
	setbkcolor(RGB(80,42,9,));
	cleardevice();
	settextcolor(WHITE);
    settextstyle(35, 0,"Î¢ÈíÑÅºÚ");
	outtextxy(50,10,"2048³¯´ú°æ");
	int x, y, k;
	for (i = 0; i < 4;i++)
	{
	    for (j = 0; j < 4; j++)
		{
		   x = 60 * j;
		   y = 60 * i + 50;
		   for(k = 0; k < 12; k++)
		   {   
			 if(imgIndex[k] == map[i][j]) 
			   break;
		   }
		   putimage(x, y, img + k);
		}
	}
}
int randIntNum()
{
	srand((unsigned int)time(NULL));
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++ )
		{
			if(map[i][j]== 0)
			{
			   map[i][j]=(rand()%3)*2;
			   if (map[i][j]==0)
			       continue;
			return 0 ;
	   		}
		}
	}
	return 0;
}
int moveRight()
{
	int flag = 0;
	for( i = 0; i < 4; i++)
	{
		for (j=4 - 1;j>=0; j--)
		{
		     int curKey = map[i][j];
			 if (curKey !=0)
			 {
			  int k = j - 1;
			  while (k >= 0)
			  {
			       int curKeyNext = map[i][k];
				   if (curKeyNext !=0)
				   {
					   if(curKey==curKeyNext)
					   {
					      flag = 1;
						  map[i][j] += map[i][k];
						  map[i][k] = 0;
					   }
					   k=-1;
					   break;
				   }
				   k--;
			   } 
			 }


			 
			    
		}
	}
	for (i = 0;i < 4; i++)
	{
		for(j = 4-1;j >= 0;j--)
		{
		    int curKey = map[i][j];
			if (curKey == 0 )
			{
			int k =  j-1;
		    while(k>=0)
			  {
				    int curKeyNext = map[i][k];
					if (curKeyNext != 0)
					{
					    flag = 1;
						map[i][j] = curKeyNext;
						map[i][k] = 0;
						k= -1;
					}
					k--;
			  }
			}
		}
	}
	if(flag)
		return 0;
	else
		return 4;


}
int moveLeft()
{
	int flag = 0;
	for( i = 0; i < 4; i++)
	{
		for (j=0;j<4; j++)
		{
		     int curKey = map[i][j];
			 if (curKey!=0)
			 {
			    int k = j + 1;
			    while (k < 4)
			    {
			       int curKeyNext = map[i][k];
				   if (curKeyNext !=0)
				    {
					    if(curKey==curKeyNext)
					    {
					      flag = 1;
						  map[i][j] += map[i][k];
						  map[i][k] = 0;
					    }
			 		    k=4;
					    break;
				    }
			 
			     }
				 k++;
			 } 
		}
	}
	for (i = 0;i < 4; i++)
	{
		for(j = 0;j <4 ;j++)
		{
		    int curKey = map[i][j];
			if (curKey == 0 )
			{
			    int k =  j+1;
				while(k < 4)
				{
				    int curKeyNext = map[i][k];
					if (curKeyNext != 0)
					{
					    flag = 1;
						map[i][j] = curKeyNext;
						map[i][k] = 0;
						k= 4;
					}
					k++;
				}
			}
		}
	}
	if(flag)
		return 0;
	else
		return 4;
}
int moveUp()
{
	int flag = 0;
	for( i = 0; i < 4; i++)
	{
		for (j=0;j<4; j++)
		{
		     int curKey = map[i][j];
			 if (curKey !=0)
			 {
			  int k = i + 1;
			  while (k < 4)
			  {
			       int curKeyNext = map[k][j];
				   if (curKeyNext !=0)
				   {
					   if(curKey==curKeyNext)
					   {
					      flag = 1;
						  map[i][j] += curKeyNext;
						  map[i][k] = 0;
					   }
					   k=4;
					   break;
				   }
				   k++;
			   } 
			 }


			 
			    
		}
	}
	for (i = 0;i < 4; i++)
	{
		for(j = 4-1;j >= 0;j++)
		{
		    int curKey = map[i][j];
			if (curKey == 0 )
			{
			int k =  i+1;
		    while(k>=0)
			  {
				    int curKeyNext = map[i][k];
					if (curKeyNext != 0)
					{
					    flag = 1;
						map[i][j] = curKeyNext;
						map[k][i] = 0;
						k= 4;
					}
					k++;
			  }
			}
		}
	}
	if(flag)
		return 0;
	else
		return 4;


}
int moveDown()
{
    int flag = 0;
		for (i=4-1;i>=0; i--)
		{
			for(j=0;j<4; j++)
			{
			    int curKey = map[i][j];
				if(curKey!=0)
				{
				    int k = i - 1;
					while(k>=0)
					{
					      int curKeyNext = map[k][j];
						  if(curKeyNext != 0)
						  {
							  if (map[i][j] == map[k][j])
							  {
							     flag = 1;
							     map[i][j] += map[k][j];
							     map[k][j] = 0;
							  
							   }
							   k=0;
				               break;
							 
						  }
						  k--;
					     
					} 
					
				}
			} 
		}
		for(i=4-1; i>0; i--)
		{
			for(j=0;j<4;j++)
			{
			   int curKey = map[i][j];
			   if  (curKey == 0)
			   {
			       int k=i-1;
				   while(k>=0)
				   {
				      int curKeyNext = map[k][j];
					  if (curKey!=0)
					  {
					      flag=1;
						  map[i][j]=curKeyNext;
						  map[k][j]=0;
						  k=0;
					  }
					  k--;
				   }

			   }
			}
		
		}
		if(flag)
		   return 0;
		else
		   return 4;
}
void keyDown()
{
	char key=_getch();
	switch (key)
	{
	case 'w':
	case 'W':
	case 72:
		randIntNum();
		moveUp();
		break;
    case 's':
	case 'S':
	case 80:
		randIntNum();
		moveDown();
		break;
	case 'a':
	case 'A':
	case 75:
		randIntNum();
		moveLeft();
		break;
	case 'd':
	case 'D':
	case 77:
		randIntNum();
		moveRight();
		break;
	}
}
int main()
{
  loadResource();
  initgraph(60*4,60*5);
  drawMap();
  while(1)
  {
    keyDown();
	drawMap();
  }
  getchar();
  closegraph();
  system("pause");
  return 0;
}
