#pragma once

#include <string>

class HitBox
{
private:
	//Hitbox ��������
	int center_x;
	int center_y;

	//hitbox����[square/circle]
	std::string hitbox_category;

public:
	HitBox();

	/*�����ж�
	 * ����hitbox��������������Ĳ�ͬ
	 * ѡ���Ӧ���ж�����
	 * ���з���true,���򷵻�false
	 * */
	bool hit(std::string weapon_category);

    bool square_hitbox_hit_by_bullet();

    bool square_hitbox_hit_by_beam();

    bool circle_hitbox_hit_by_bullet();

    bool circle_hitbox_hit_by_beam();
	~HitBox();
};