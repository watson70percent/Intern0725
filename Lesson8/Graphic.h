#pragma once
class Graphic {
public:
	void HotSpring(int x,int height,int sky, int level);
	void Title();
	void Standby(int level,int width);
	void Win();
	void Lose(int level);
	void End();
	void Clear();
};