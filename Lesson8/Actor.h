#pragma once
class Actor {
public:
	Actor() {}
	virtual ~Actor() {}
	//virtual void Update() = 0;
	virtual void Move(int x, int y) = 0;
	virtual void Update() = 0;
	virtual void Dig() = 0;
	int GetX() { return x; }
	int GetY() { return y; }
protected:
	int x = 10, y = 0;
	int dir_x, dir_y;
};