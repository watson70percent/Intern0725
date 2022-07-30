#pragma once
#include "Actor.h"
#include "Stage.h"

//! 継承は以下のようにします
class Enemy : public Actor
{
public:
	Enemy();
	//TODO: 実装してくだい
public:
	void Move(int m_x, int m_y);
	void Update();
	void Dig();
	void Reset();
	void Init(Stage* stg);
protected:
	Stage* stage=nullptr;
};