#pragma once
class Stage {
public:
	Stage(int _width, int _height);
	//デストラクタ
	~Stage();
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	int GetSky() { return sky; }
	int Check(int x, int y);
	void Init(int sky);

	void Digged(int x, int y);
private:
	int height, width, length, sky;
	int* blocks;
};
