#pragma once
#include "Enemy.h"
#include "../Lesson5/PoolAllocator.h"
#include "Data.h"
#include "Stage.h"

class EnemyManager{
	PoolAllocator<Enemy, MAX_ENEMY> Enemies;
	Enemy* mEnemy[MAX_ENEMY];

public:
	EnemyManager(Stage& stg);
	~EnemyManager() {}
	void Reset(int level);
	void Update();
	bool Hit(int px, int py);
private:
	int enemyNum;
	Stage& stage;
};