#include "Enemy.h"
#include <stdio.h>
#include <conio.h>
#include <random>

std::random_device rnd;

Enemy::Enemy() { x = 0; y = 0; dir_x = 0; dir_y = 0;}

void Enemy::Move(int m_x, int m_y) {
	printf("\x1b[%d;%dH ", y, x + 20); // 前の座標に' '表示
	//縦移動が優先
	int moved = 0;
	for (int i = 0; i < m_y; i++) {
		if (0 == stage->Check(x, y + 1)) {
			y++;
			moved = 1;
		}
	}
	if(0==moved) {
		Dig();
		x += m_x;
	}
	printf("\x1b[%d;%dHK", y, x + 20); // 今の座標に'@'表示
}

void Enemy::Dig() {
	stage->Digged(x + dir_x, y + dir_y);
}

void Enemy::Update() {
	//移動方向の判定
	if (x <= 0)dir_x = 1;
	if (x >= stage->GetWidth()-1)dir_x = -1;
	Move(dir_x, 2);
}

void Enemy::Reset() {
	x = 0;
	y = 0;
	dir_x = 0;
	dir_y = 0;
}

void Enemy::Init(Stage* stg) {
	stage = stg;
	x = rnd() % stage->GetWidth();
	y = rnd() % (stage->GetHeight() - stage->GetSky() -2) + stage->GetSky()+1;
	dir_x = rnd()%2*2-1;
	dir_y = 0;
	printf("\x1b[%d;%dHK", y, x + 20); // 今の座標に'@'表示
}