#pragma once
#include "Actor.h"
#include "Stage.h"

//! Œp³‚ÍˆÈ‰º‚Ì‚æ‚¤‚É‚µ‚Ü‚·
class Enemy : public Actor
{
public:
	Enemy();
	//TODO: À‘•‚µ‚Ä‚­‚¾‚¢
public:
	void Move(int m_x, int m_y);
	void Update();
	void Dig();
	void Reset();
	void Init(Stage* stg);
protected:
	Stage* stage=nullptr;
};