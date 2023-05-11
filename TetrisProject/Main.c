#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define sizeY 22 // x좌표의 블럭 중앙 생성 좌표 : x=4, y=1
#define sizeX 12
#define bsizeX 4
#define bsizeY 4

typedef struct blkstruct {
	int bType;
	int bState;
	int x;
	int y;
}blk;

int table[sizeY][sizeX] = {
	{2, 2,2,2,2,2,2,2,2,2,2, 2},//0
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//1
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//2
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//3
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//4
	{2, 0,0,0,0,0,0,0,0,0,0, 2},//5
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

// block[7종류] [4가지회전상태] [x*4] [y*4]
int block[7][4][4][4] = {
	// i 블럭
	{
		{
			// 0번상태
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			// 1번상태
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{
			// 2번상태
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},
		{
			// 3번상태
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
	},
	// ㅁ 블럭
	{
		{
			// 0번상태
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			// 1번상태
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			// 2번상태
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			// 3번상태
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
	}	,
	// T 블럭
	{
		{
			// 0번상태
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			// 1번상태
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			// 2번상태
			{0,0,0,0},
			{1,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			// 3번상태
			{0,1,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
	},
	// L 블럭
	{
		{
			// 0번상태
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			// 1번상태
			{0,1,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			// 2번상태
			{0,0,0,0},
			{1,1,1,0},
			{1,0,0,0},
			{0,0,0,0}
		},
		{
			// 3번상태
			{1,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
	},
	//J 블럭
	{
		{
			// 0번상태
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			// 1번상태
			{0,1,1,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			// 2번상태
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			// 3번상태
			{0,1,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,0,0,0}
		},
	},
	//S 블럭
	{
		{
			// 0번상태
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			// 1번상태
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			// 2번상태
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			// 3번상태
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
	},
	// Z 블럭
	{
		{
			// 0번상태
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			// 1번상태
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			// 2번상태
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			// 3번상태
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{0,0,0,0}
		},
	}
};

int gTime = 0;
int bList[7];
int bTypeQptr;
int pull = 0;
int fallspeed;
int tScore = 0;

void drawTable();
void drawBlock(blk* myblk);
void appendProcess(blk* myblk);
void gotoxy(int x, int y);
void blockFallProcess(blk* myblk);
int checkProcess(blk* myblk);
void blockinitProcess(blk* myblk);
void keyProcess(blk* myblk);
void gameover();
int removeProcess();
void printInfo(blk* myblk);

int main() {
	srand(time(NULL));
	fallspeed = 10;

	blk myblk;
	blk* myblkPtr = &myblk;
	bTypeQptr = 7;
	blockinitProcess(myblkPtr);

	// 커서 감추기
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;

	while (1) {
		drawTable();
		gTime++;

		printInfo(myblkPtr);
		keyProcess(myblkPtr);
		drawBlock(myblkPtr);
		blockFallProcess(myblkPtr);

		Sleep(30);
	}
}

void printInfo(blk* myblk) {
	int i;
	printf("time:%d, (%d, %d) %d\n\n", gTime, myblk->x, myblk->y, kbhit());
	printf("block List : ");
	for (i = 0; i < 7; i++) {
		printf("%d ", bList[i]);
	}
	printf("\n             ");
	for (i = 0; i < bTypeQptr; i++) {
		printf("  ");
	}
	printf("=");
	for (i = bTypeQptr; i < 6; i++) {
		printf("  ");
	}
	printf("\nTetris : %d", tScore);
	printf("\n %d", myblk->bState);
}

// 테이블 그리기
void drawTable() {
	int i, k;
	gotoxy(0, 0);
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
}

// 블럭 이동(화면상에만 표시)
void drawBlock(blk* myblk) {
	int i, k;

	for (i = 0; i < bsizeY; i++)
	{
		for (k = 0; k < bsizeX; k++) {
			gotoxy(myblk->x * 2 + k * 2, myblk->y + i);
			if (block[myblk->bType][myblk->bState][i][k])
				printf("■");
		}
	}
}


// 블럭을 테이블에 저장
void appendProcess(blk* myblk) {
	int i, k;

	for (i = 0; i < bsizeY; i++)
	{
		for (k = 0; k < bsizeX; k++) {
			if (block[myblk->bType][myblk->bState][i][k])
				table[i + myblk->y][k + myblk->x] = 1;
		}
		printf("\n");
	}
	blockinitProcess(myblk);
}

// 블럭 하강
void blockFallProcess(blk* myblk) {
	if (!(gTime % fallspeed)) {
		myblk->y = myblk->y + 1;
		if (checkProcess(myblk)) {
			myblk->y = myblk->y - 1;
			appendProcess(myblk);
		}
		else if (pull) {
			pull = 0;
			myblk->y = myblk->y - 1;
		}
	}

}

// 블럭 초기화 프로세스
void blockinitProcess(blk* myblk) {
	int i, k;

	myblk->bState = 0;
	myblk->x = 4;
	myblk->y = 1;

	bTypeQptr++;

	if (bTypeQptr > 6) {
		bTypeQptr = 0;
		for (i = 0; i < 7; i++) {
			bList[i] = (rand() % 7 + 0);
			for (k = 0; k < i; k++) {
				if (bList[i] == bList[k]) {
					i--;
				}
			}
		}
	}

	myblk->bType = bList[bTypeQptr];
	k = removeProcess();

	if (checkProcess(myblk))
		gameover();
}

// 커서 이동
void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 블럭의 충돌여부 확인
int checkProcess(blk* myblk) {
	int i, k;

	for (i = 0; i < bsizeY; i++)
	{
		for (k = 0; k < bsizeX; k++) {
			if (block[myblk->bType][myblk->bState][i][k] && table[i + myblk->y][k + myblk->x])
				return 1;
		}
	}
	return 0;
}

// 키 프로세스
void keyProcess(blk* myblk) {
	int i;
	if (kbhit()) {
		char c;
		int beforeX = myblk->x;
		int beforeY = myblk->y;
		int beforeState = myblk->bState;

		c = getch();

		switch (c)
		{
		case 77:
			myblk->x += 1;
			break;
		case 75:
			myblk->x -= 1;
			break;
		case 'z':
			myblk->bState = (myblk->bState + 1) % 4;
			// 빈 공간 찾아서 들어가기
			if (checkProcess(myblk)) {
				for (i = 3; i > -3; i -= 2) {
					myblk->y += i % 3;
					if (!checkProcess(myblk))
						break;
					myblk->x -= 1;
					if (!checkProcess(myblk))
						break;
					myblk->x += 2;
					if (!checkProcess(myblk))
						break;
				}
			}
			break;
		case 'x':
			myblk->bState = myblk->bState - 1 >= 0 ? (myblk->bState - 1) : 3;
			
			// 빈 공간 찾아서 들어가기
			if (checkProcess(myblk)) {
				for (i = 3; i > -3; i -= 2) {
					myblk->y += i % 3;
					if (!checkProcess(myblk))
						break;
					myblk->x -= 1;
					if (!checkProcess(myblk))
						break;
					myblk->x += 2;
					if (!checkProcess(myblk))
						break;
				}
			}
			break;
		case 80:
			fallspeed = 1;
			break;
		default:
			break;
		}

		if (checkProcess(myblk)) {
			myblk->x = beforeX;
			myblk->y = beforeY;
			myblk->bState = beforeState;
		}
	}
	else {
		fallspeed = 10;
	}
}

// 블럭 제거 프로세스
int removeProcess() {
	int i, k, line = -1;
	for (i = 1; i < sizeY - 1; i++)
	{
		for (k = 1; k < sizeX - 1; k++) {
			if (!table[i][k])
				break;
		}
		if (k == sizeX - 1) {
			line = i;
			break;
		}
	}
	if (line == -1)
		return 0;

	for (i = line; i > 1; i--) {
		for (k = 1; k < sizeX - 1; k++)
			table[i][k] = table[i - 1][k];
	}
	for (k = 1; k < sizeX - 1; k++)
		table[1][k] = 0;
	tScore++;
	return removeProcess();
}

void gameover() {
	gotoxy(0, 10);
	printf("□      GameOver      □");
	Sleep(100000);
	exit(0);
}
