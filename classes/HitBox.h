#pragma once

#include <string>

class HitBox
{
private:
	//hitbox����[square/circle]
	enum category_list{square, circle};

	//Hitbox ��������
	int center_x;
	int center_y;

	category_list category;

public:
	HitBox();

	/*�����ж�
	 * ����hitbox��������������Ĳ�ͬ
	 * ѡ���Ӧ���ж�����
	 * ���з���true,���򷵻�false
	 * */
	bool hit();

    bool square_hitbox_hit_by_bullet();

    bool square_hitbox_hit_by_beam();

    bool circle_hitbox_hit_by_bullet();

    bool circle_hitbox_hit_by_beam();
	~HitBox();
};