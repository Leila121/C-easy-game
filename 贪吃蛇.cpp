#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define High 20  // 游戏画面尺寸
#define Width 30

// 全局变量
int canvas[High][Width] = { 0 }; 


void gotoxy(int x, int y) //光标移动到(x,y)位置
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}



void startup() // 数据初始化
{

}

void show()  // 显示画面
{
	gotoxy(0, 0);  // 光标移动到原点位置，以下重画清屏

	int i, j;

	for (i = 0; i <= High; i++)
	{
		for (j = 0; j <= Width; j++)
		{
			if (canvas[i][j] == 0)
				printf(" ");  //   输出空格
			else if (canvas[i][j] == -1)
				printf("#");  //   输出边框#
			else if (canvas[i][j] == 1)
				printf("@");  //   输出蛇头@
			else if (canvas[i][j] > 1)
				printf("*");  //   输出蛇身*
		}
		printf("\n");
	}
}

void updateWithoutInput()  // 与用户输入无关的更新
{

}

void updateWithInput()  // 与用户输入有关的更新
{

}

int main()
{
	startup();  // 数据初始化	
	while (1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
	return 0;
}
