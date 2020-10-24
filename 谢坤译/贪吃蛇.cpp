#include<bits/stdc++.h>
#include< conio.h>
using namespace std;
int main() {
	int i, j,k;
	int pane[4][4] = { 0 };
	int  y, x;
	char m;
	//打印
	
	while (1) {
		system("color 0B");
		system("CLS");


		while (1) {
			srand((int)time(0));
			i = rand() % 4;
			j = rand() % 4;
			if (pane[i][j] == 0) { pane[i][j] = 2; break; }
		}
		cout << "MSC 2048 by xky" << endl;
		cout << "-----------------------------" << endl;
		cout << " |";
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
			{
				cout << pane[i][j] << " |"; if (j == 3) cout << endl;
				cout << " |";
			}

		cout << "------------------------------" << endl;

		m = _getch();
		//向下移动
		if (m == 's') {
			for (j = 0; j < 4; j++)
			{
				k = 3;
				for (i = 3; i >= 0; i--)
				{
					if (pane[i][j] != 0 && i != k) { pane[k][j] = pane[i][j]; pane[i][j] = 0; k--; }
					if (pane[i][j] != 0 && i == k) k--;
				}
			}
			for (j = 0; j < 4; j++)
			{
				for (i = 3; i > 1; i--)
					if (pane[i][j] == pane[i - 1][j]) {
						pane[i][j] += pane[i - 1][j]; pane[i - 1][j] = 0; do {
							pane[i - 1][j] = pane[i - 2][j]; i--;
						} while (i - 2 > 0);
						pane[0][j] = 0;
					}
				if (pane[0][j] == pane[1][j]) { pane[1][j] += pane[0][j]; }


				pane[0][j] = 0;
			}

		}


		//向上移动
		if (m == 'w')
		{
			for (j = 0; j < 4; j++)
			{
				k = 0;
				for (i = 0; i < 4; i++)
				{
					if (pane[i][j] != 0 && i != k) { pane[k][j] = pane[i][j]; pane[i][j] = 0; k++; }
					if (pane[i][j] != 0 && i == k)k++;
				}

			}
			for (j = 0; j < 4; j++)
			{
				for (i = 0; i < 2; i++)
					if (pane[i][j] == pane[i + 1][j]) {
						pane[i][j] += pane[i + 1][j]; pane[i + 1][j] = 0; do {
							pane[i + 1][j] = pane[i + 2][j]; i++;
						} while (i + 2 < 4);
						
						pane[3][j] = 0;
					}
				if (pane[3][j] == pane[2][j]) { pane[2][j] += pane[3][j]; }
				pane[3][j] = 0;
			}
          }





		//向左移动
		if (m == 'a') {
			for (i = 0; i < 4; i++)
			{
				k = 0;
				for (j = 0; j<4; j++)
				{
					if (pane[i][j] != 0 && j != k) { pane[i][k] = pane[i][j]; pane[i][j] = 0; k++; }
					if (pane[i][j] != 0 && j == k) k++;
				}
			}
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 2; j++)
					if (pane[i][j] == pane[i][j + 1]) {
						pane[i][j] += pane[i][j + 1]; pane[i][j + 1] = 0; do {
							pane[i][j + 1] = pane[i][j + 2]; j++;
						} while (j + 2 < 4);
						
						pane[i][3] = 0;
					}
				if (pane[i][3] == pane[i][2])    pane[i][2] += pane[i][3];
				pane[i][3] = 0;


			}
		}
		//向右移动
		if (m == 'd') {
			for (i = 0; i < 4; i++)
			{
				k = 3;
				for (j = 3; j>=0; j--)
				{
					if (pane[i][j] != 0 && j != k) { pane[i][k] = pane[i][j]; pane[i][j] = 0; k--; }
					if (pane[i][j] != 0 && j == k) k--;
				}
			}

			for (i = 0; i < 4; i++)
			{
				for (j = 3; j > 1; j--)
					if (pane[i][j] == pane[i][j - 1]) {
						pane[i][j] += pane[i][j - 1]; pane[i][j - 1] = 0; do {
							pane[i][j - 1] = pane[i][j - 2]; j--;
						} while (j - 2 > 0);
						
						pane[i][0] = 0;
					}
				if (pane[i][0] == pane[i][1])    pane[i][1] += pane[i][0];
				pane[i][0] = 0;
			}
		}

		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (pane[i][j] == 2048)
					goto quit;




	}quit:
	cout << "win";
}