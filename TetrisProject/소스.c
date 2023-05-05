#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#define sizeY 22
#define sizeX 12

void drawTable();

int mtable[sizeX] = {0, 0,0,0,0,0,0,0,0,0,0, 0};

int table[sizeY][sizeX] = { 
	{2, 2,2,2,2,2,2,2,2,2,2, 2},//0
	{2, 1,0,0,0,0,0,0,0,0,1, 2},//1
	{2, 0,1,0,0,0,0,0,0,1,0, 2},//2
	{2, 0,0,1,0,0,0,0,1,0,0, 2},//3
	{2, 0,0,0,1,0,0,1,0,0,0, 2},//4
	{2, 0,0,0,0,1,1,0,0,0,0, 2},//5
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//6
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//7
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//8
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//9
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//10
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//11
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//12
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//13
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//14
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//15
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//16
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//17
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//18
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//19
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//20
	{2, 2,2,2,2,2,2,2,2,2,2, 2} //21
};

int main() {
	int i = 0;
	int gTime = 0;
	char c;
	int playerx = 1;

	// 커서 감추기
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;

	while (1) {
		system("cls");
		drawTable();

		if (kbhit()) {	// 테스트용 플레이어 개체 
			c = getch();
			if (c == 'd') {
				playerx++;
			}
			else if (c == 'a') {
				playerx--;
			}
		}	// 테스트용 플레이어 개체 
		for (i = 0; i < sizeX; i++) {	// 테스트용 플레이어 개체 
			if (i == playerx)
				mtable[i] = 1;
			else
				mtable[i] = 2;
		}	// 테스트용 플레이어 개체 

		gTime++;
		printf("%d", gTime);

		Sleep(50);
	}
	return 0;
}

void drawTable() {
	int i, k, j;
	for (i = 0; i < sizeY; i++)
	{
		for (k = 0; k < sizeX; k++) {
			switch (table[i][k])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("□");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}

	for (j = 0; j < sizeX; j++) {	// 테스트용 플레이어 개체 
		switch (mtable[j])
		{
		case 1:
			printf("■");
			break;
		case 2:
			printf("□");
			break;
		default:
			break;
		}
	}	// 테스트용 플레이어 개체 




}