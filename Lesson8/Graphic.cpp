#include "Graphic.h"
#include <stdio.h>
#include <windows.h>

void Graphic::HotSpring(int x, int height, int sky, int level) {
	int y = 0;
	for (y = height; y > sky-4; y--) {
		printf("\x1b[%d;%dH @ ", y-1, x-1+20); // ç°ÇÃç¿ïWÇ…'@'ï\é¶
		printf("\x1b[%d;%dH M ", y, x-1+20); // ç°ÇÃç¿ïWÇ…'@'ï\é¶
		Sleep(100);
	}

	printf("\x1b[%d;%dHLEVEL %d Clear!!", y-3, x-7+20,level);
	printf("\x1b[%d;%dH   ___  @  ___", y-2, x - 8+20);
	printf("\x1b[%d;%dH Å^   Å_ Å^   Å_", y-1, x - 8+20);
	printf("\x1b[%d;%dH V ", y, x - 1+20);
	Sleep(2000);
}

void Graphic::Title() {
	printf("\x1b[%d;%dHâ∑êÚÉzÉäÉâÅ[", 10, 20);
	printf("\x1b[%d;%dHpress SPACE",11,20);
}

void Graphic::Standby(int level,int width) {
	system("cls");
	printf("\x1b[%d;%dHLEVEL %d", 0, 0, level);
	printf("\x1b[%d;%dHD:å@ÇÈ", 20, 4);
	printf("\x1b[%d;%dH K", 18, 20 + width + 8);
	printf("\x1b[%d;%dH Å™", 19, 20 + width +8);
	printf("\x1b[%d;%dHHÅ©  Å®L", 20, 20 + width + 6);
	printf("\x1b[%d;%dH Å´", 21, 20 + width + 8);
	printf("\x1b[%d;%dH J", 22, 20 + width + 8);
}

void Graphic::Win() {
	system("cls");
}

void Graphic::Lose(int level) {
	Sleep(2000);
	system("cls");
	printf("\x1b[%d;%dHSCORE %d", 9, 20,level);
	printf("\x1b[%d;%dHGameOver", 10, 20);
}

void Graphic::End() {
	printf("\x1b[%d;%dHSPACE:RESTART  Q:QUIT", 11, 17);
}

void Graphic::Clear() {
	system("cls");
	printf("\x1b[%d;%dHALL CLEAR", 9, 20);
	printf("\x1b[%d;%dHGameOver", 10, 20);
}