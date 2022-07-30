#pragma once
#include "Actor.h"
#include "Stage.h"

//! Œp³‚ÍˆÈ‰º‚Ì‚æ‚¤‚É‚µ‚Ü‚·
class Player : public Actor
{
public:
	Player(Stage& stg);
	//TODO: À‘•‚µ‚Ä‚­‚¾‚¢
public:
	void Move(int m_x, int m_y);
	void Update();
	void Dig();
	int GoalCheck();
	void Goal();
	void Reset();
protected:
	Stage& stage;
	int left;
};