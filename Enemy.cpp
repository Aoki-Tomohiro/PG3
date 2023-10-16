#include "Enemy.h"

//メンバ関数ポインタテーブルの実体定義
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::CloseRangeAttack,//要素番号0
	&Enemy::ShootingAttack,//要素番号1
	&Enemy::Leave,//要素番号2
};

void Enemy::Update() {
	//メンバ関数ポインタの呼び出し
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
	phase_ = Phase::kShootingAttack;
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
	phase_ = Phase::kLeave;
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

void Enemy::CloseRangeAttack() {
	std::cout << "敵の状態 : 近接攻撃" << std::endl;
}

void Enemy::ShootingAttack() {
	std::cout << "敵の状態 : 射撃攻撃" << std::endl;
}

void Enemy::Leave() {
	std::cout << "敵の状態 : 離脱" << std::endl;
}