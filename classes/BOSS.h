#pragma once
#include "Enemy.h"
class BOSS :
	public Enemy
{
private:
	//���弰����������ֵ
	int max_health[5];
	int health[5];

	//BOSS�Ķ��ж���
	HitBox hitboxs[5];

public:
	BOSS();

	bool damage;

	~BOSS();
};

