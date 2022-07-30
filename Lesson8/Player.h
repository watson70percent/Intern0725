#pragma once
#include "Actor.h"
#include "Stage.h"

//! �p���͈ȉ��̂悤�ɂ��܂�
class Player : public Actor
{
public:
	Player(Stage& stg);
	//TODO: �������Ă�����
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