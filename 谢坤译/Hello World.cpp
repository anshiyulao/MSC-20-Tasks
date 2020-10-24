//C++-------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main() {
	cout << "Hello World" << endl;
	return 0;
}

//上下跳动的Hello world------------------------
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main() {
    int i, j, x = 1, y = 20, v = 1;

    while (1) {
        if (x > 10) v = -1;
        if (x == 1)  v = 1;
        x += v;
        system("color 0A");
        system("CLS");
        for (i = 0; i < x; i++)
            cout << "\n";
        for (j = 0; j < y; j++)
            cout << " ";
        Sleep(1);
        cout << "Hello World !";



    }return 0;

}

//C------------------------------------------------
#include <stdio.h>
int main()
{
	printf("Hello World!");
	return 0;
}

///C   sleep函数----------------------------------------
#include<stdio.h>
#include<windows.h>
int main()
{
    printf("H");
    Sleep(500);

    printf("e");
    Sleep(500);

    printf("l");
    Sleep(500);

    printf("l");
    Sleep(500);

    printf("o  ");
    Sleep(500);

    printf("W");
    Sleep(500);

    printf("o");
    Sleep(500);

    printf("r");
    Sleep(500);

    printf("l");
    Sleep(500);

    printf("d  ");
    Sleep(500);

    printf("!");
    Sleep(500);

    return 0;
}


//python------------------------------------------
print("hello world")



//JavaScript
document.write('Hello, World!');