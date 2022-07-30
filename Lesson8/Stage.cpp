#include "Stage.h"
#include <stdio.h>

Stage::Stage(int _width, int _height) {
	height = _height;
	width = _width;
	sky = 0;
	length = height * width;
	blocks = new int[length];
	//ステージ初期化

}

Stage::~Stage() {
	delete blocks;
}

void Stage::Init(int _sky) {
	sky = _sky;
	for (int y = 0; y < sky; y++) {
		for (int x = 0; x < width; x++) {
			blocks[y * width + x] = 0;
		}
	}
	for (int y = sky; y < height; y++) {
		for (int x = 0; x < width; x++) {
			blocks[y * width + x] = 1;
			printf("\x1b[%d;%dH:", y, x + 20); // 座標に'#'表示
		}
	}

}

int Stage::Check(int x, int y) { return blocks[y * width + x]; }

void Stage::Digged(int x, int y) {
	if (0 <= x && x < width && 0 <= y && y < height) {
		blocks[y * width + x] = 0;
		printf("\x1b[%d;%dH ", y, x+20); // 座標に'#'表示
	}
}