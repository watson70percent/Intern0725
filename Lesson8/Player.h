#pragma once
#include "Actor.h"
#include "Stage.h"

//! 継承は以下のようにします
class Player : public Actor
{
public:
	Player(Stage& stg);
	//TODO: 実装してくだい
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