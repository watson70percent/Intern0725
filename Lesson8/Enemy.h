#pragma once
#include "Actor.h"
#include "Stage.h"

//! �p���͈ȉ��̂悤�ɂ��܂�
class Enemy : public Actor
{
public:
	Enemy();
	//TODO: �������Ă�����
public:
	void Move(int m_x, int m_y);
	void Update();
	void Dig();
	void Reset();
	void Init(Stage* stg);
protected:
	Stage* stage=nullptr;
};