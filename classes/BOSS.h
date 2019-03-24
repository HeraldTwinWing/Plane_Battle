#pragma once
#include "Enemy.h"
class BOSS :
	public Enemy
{
private:
	//本体及部件的生命值
	int max_health[5];
	int health[5];

	//BOSS的多判定点
	HitBox hitboxs[5];

public:
	BOSS();

	bool damage;

	~BOSS();
};

