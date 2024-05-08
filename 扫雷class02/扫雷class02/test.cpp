#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#define PICTURE 40

//随机数
void Insert(int* arr, int row, int col, int n)
{
	//初始化
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i * row + j] = 0;
		}
	}

	//真随机数
	static unsigned int s = time(NULL);
	srand(s);
	s = rand();

	int x, y;
	while (n)
	{
		x = rand() % row;
		y = rand() % col;
		if (arr[x * row + y] == 0)
		{
			arr[x * row + y] = rand() % 8 + 1;
			n--;
		}
	}

}


//输出
void print(int* arr, int row, int col,IMAGE image[])
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i * row + j]);
			putimage(i * PICTURE, j * PICTURE, &image[arr[i * row + j]]);
		}
		printf("\n");
	}
}

//鼠标信息
void mouse(IMAGE image[],int* arr,int row)
{
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		int y = msg.y / PICTURE ;
		int x = msg.x / PICTURE ;
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			//putimage(x * PICTURE, y * PICTURE, &image[arr[x * row + y]]);
			//arr[x * row + y]++;

			//左击鼠标，键盘修改
			int key = (int)_getch() - '0';
			putimage(x * PICTURE, y * PICTURE, &image[key]);
			arr[x * row + y] = key;
		}
		if (msg.uMsg == WM_RBUTTONDOWN)
		{
			//右击鼠标，减一
			putimage(x * PICTURE, y * PICTURE, &image[arr[x * row + y]]);
			arr[x * row + y]--;
		}
	}
}

int main()
{
	int row = 9;
	int col = 9;
	int num = 60;

	int* arr = new int[row*col];

	//加载图片
	IMAGE image[9];
	for (int i = 0; i < 9; i++)
	{
		char number[100];
		sprintf(number, ".\\images\\%d.jpg", i);
		loadimage(&image[i], number);
	}

	initgraph(col * PICTURE, row * PICTURE, EX_SHOWCONSOLE);
	Insert(arr, row, col, num);
	print(arr, row, col,image);
	while (1)
	{
		mouse(image,arr,row);
	}

	return 0;
}