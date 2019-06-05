#pragma once

#include <string>
#include "Weapon.h"

enum hitbox_category
{
	SQUARE_HITBOX, CIRCLE_HITBOX
};

class HitBox
{
private:
	hitbox_category category;
	int radius;
public:

	// Hitbox ��������
	// ��Plane::refresh��ˢ��
	int center_x;
	int center_y;

	//hitbox_category category;
	//int size[2];


	HitBox(hitbox_category category, int radius);

	/*�����ж�
	 * ����hitbox��������������Ĳ�ͬ
	 * ѡ���Ӧ���ж�����
	 * ���з���true,���򷵻�false
	 * */
	bool hit(WeaponCategoryEnum weaponCategoryEnum, Bullet *bullet = nullptr);

	bool ifBulletHit(Bullet *bullet);

	bool ifBeamHit();

	void set_x(int x);

	void set_y(int y);

	~HitBox();


};