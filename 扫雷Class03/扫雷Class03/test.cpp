#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#define PICTURE 40

//�����
void Insert(int* arr, int row, int col, int n)
{
	//��ʼ��
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i * row + j] = 0;
		}
	}

	//�������
	static unsigned int s = time(NULL);
	srand(s);
	s = rand();

	int x, y;
	while (n)
	{
		x = (rand() % (row-2))+1;
		y = (rand() % (col-2))+1;
		
		if (arr[x * row + y] == 0)
		{
			//���ף��׵�ͼƬ�±�Ϊ9
			arr[x * row + y] = 9;
			n--;
		}
	}

	//ÿ��������������Χ�׵�����
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (arr[i * row + j] != 9)
			{
				arr[i * row + j] = (arr[(i - 1) * row + (j - 1)] == 9) +
					(arr[(i - 1) * row + (j)] == 9) + (arr[(i - 1) * row + (j + 1)] == 9) +
					(arr[(i)*row + (j - 1)] == 9) + (arr[(i)*row + (j + 1)] == 9) +
					(arr[(i + 1) * row + (j - 1)] == 9) + (arr[(i + 1) * row + (j)] == 9) +
					(arr[(i + 1) * row + (j + 1)] == 9);
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[(j)*row + (i)]);
		}
		printf("\n");
	}
	printf("\n");
}


//���
void print(int* arr, int row, int col, IMAGE image[])
{

	for (int i = 0; i < row-2; i++)
	{
		for (int j = 0; j < col-2; j++)
		{
			//putimage(j * PICTURE, i * PICTURE, &image[arr[i * row + j]]);
			putimage(j * PICTURE, i * PICTURE, &image[10]);
		}
	}

	for (int i = 1; i < row-1; i++)
	{
		for (int j = 1; j < col-1; j++)
		{
			printf("%d ", arr[(j ) * row + (i)]);
		}
		printf("\n");
	}
}

//�����Ϣ
void mouse(IMAGE image[], int* arr, int row,int col,int num)
{
	static int cnt = 0;
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		int y = msg.y / PICTURE;
		int x = msg.x / PICTURE;
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			//���ɨ��
			putimage(x * PICTURE, y * PICTURE, &image[arr[(x+1) * row + (y+1)]]);
			//�ж���Ϸ����
			if (arr[(x+1) * row + (y+1)] == 9)
			{
				outtextxy(row / 2 * PICTURE, col / 2 * PICTURE, "��ը�ˣ���Ϸ����");
			}
			else
			{
				cnt++;
				if (cnt == row * col - num)
				{
					outtextxy(row / 2 * PICTURE, col / 2 * PICTURE, "��ɨ���ˣ���Ϸ����");
				}
			}
		}
		if (msg.uMsg == WM_RBUTTONDOWN)
		{
			//�һ����
			putimage(x * PICTURE, y * PICTURE, &image[11]);
		}
	}
}

int main()
{
	int row = 10;
	int col = 10;
	int num = 10;

	int* arr = new int[(row+2) * (col+2)];

	//����ͼƬ
	IMAGE image[12];
	for (int i = 0; i < 12; i++)
	{
		char number[100];
		sprintf(number, ".\\images\\%d.jpg", i);
		loadimage(&image[i], number,PICTURE,PICTURE);
	}

	initgraph(col * PICTURE, row * PICTURE, EX_SHOWCONSOLE);
	Insert(arr, row+2, col+2, num);
	print(arr, row+2, col+2, image);
	while (1)
	{
		mouse(image, arr, row+2,col+2,num);
	}

	return 0;
}
