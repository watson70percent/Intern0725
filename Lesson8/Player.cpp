#include "Player.h"
#include <stdio.h>
#include <conio.h>

Player::Player(Stage& stg) : stage(stg) { left = 3; x = 15; y = 0; dir_x = 0; dir_y = 0; }

void Player::Move(int m_x, int m_y) {
	printf("\x1b[%d;%dH ", y, x+20); // 前の座標に' '表示
	//printf("\x1b[%d;%dH(%d, %d)", 20, 50, x + m_x, y + m_y); // 座標に'#'表示
	//横移動が優先
	if (0 == stage.Check(x + m_x, y) && 0 <= x + m_x && x + m_x < stage.GetWidth()) {
		x += m_x;
	}
	if (0 == stage.Check(x + m_x, y + m_y)) {
		y += m_y;
	}
	printf("\x1b[%d;%dH@", y, x+20); // 今の座標に'@'表示
}

void Player::Update() {
	int m_x = 0;
	int m_y = 0;
	int i = 0;
	//printf("\x1b[%d;%dH@", y, x); // 今の座標に'@'表示
	if (_kbhit()) i = _getch(); // キー入力待ち
	//printf("\x1b[%d;%dH ", y, x); // 前の座標に' '表示
	++m_y;
	// キー入力で座標更新
	switch (i) {
	case 'k':
		--m_y;
		dir_x = 0;
		dir_y = -1;
		break;
	case 'h':
		--m_x;
		dir_x = -1;
		dir_y = 0;
		break;
	case 'l':
		++m_x;
		dir_x = 1;
		dir_y = 0;
		break;
	case 'j':
		dir_x = 0;
		dir_y = 1;
		break;
	case 'd':
		Dig();
		break;
	}
	Move(m_x, m_y);

}

void Player::Dig() {
	stage.Digged(x + dir_x, y + dir_y);
}

int Player::GoalCheck() { 
	return stage.GetHeight()-1 <= y;
}

void Player::Goal() {

}

void Player::Reset() {
	x = 15; y = 0;
	dir_x = 0; dir_y = 1;
}