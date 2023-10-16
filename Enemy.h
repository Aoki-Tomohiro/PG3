#pragma once
#include <iostream>

class Enemy{
public:
	//敵の状態
	enum class Phase {
		kCloseRangeAttack,
		kShootingAttack,
		kLeave,
	};

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 近接攻撃
	/// </summary>
	void CloseRangeAttack();

	/// <summary>
	/// 射撃攻撃
	/// </summary>
	void ShootingAttack();

	/// <summary>
	/// 離脱
	/// </summary>
	void Leave();

private:
	//メンバ関数ポインタのテーブル
	static void (Enemy::* spFuncTable[])();
	//敵の状態
	Phase phase_ = Phase::kCloseRangeAttack;
};

