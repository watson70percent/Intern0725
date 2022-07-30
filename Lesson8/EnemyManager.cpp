#include "EnemyManager.h"

EnemyManager::EnemyManager(Stage& stg) :stage(stg) {
	for (int i = 0; i < MAX_ENEMY; i++) {
		mEnemy[i] = nullptr;
	}
	enemyNum = 0;
}

void EnemyManager::Reset(int level){
	//一掃する
	for (int i = 0; i < MAX_ENEMY; i++) {
		if (mEnemy[i] != nullptr) {
			Enemies.Free(mEnemy[i]);
			mEnemy[i]->Reset();
			mEnemy[i] = nullptr;
		}
	}
	enemyNum = 0;
	//レベルに応じてセット
	for (int i = 0; i < MAX_ENEMY && i < level; i++) {
		if (mEnemy[i] == nullptr) {
			mEnemy[i] = Enemies.Alloc();
			mEnemy[i]->Init(&stage);
			enemyNum++;
		}
	}
}

void EnemyManager::Update() {
	for (int i = 0; i < enemyNum; i++) {
		mEnemy[i]->Update();
	}
}

bool EnemyManager::Hit(int px, int py) {
	for (int i = 0; i < enemyNum; i++) {
		if (mEnemy[i]->GetX() == px && mEnemy[i]->GetY() == py)return true;
	}
	return false;
}