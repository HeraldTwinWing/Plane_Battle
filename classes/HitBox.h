#pragma once

#include <string>

class HitBox
{
private:
	//hitbox种类[square/circle]
	enum category_list{square, circle};

	//Hitbox 中心坐标
	int center_x;
	int center_y;

	category_list category;

public:
	HitBox();

	/*击中判定
	 * 根据hitbox种类与武器种类的不同
	 * 选择对应的判定方法
	 * 击中返回true,否则返回false
	 * */
	bool hit();

    bool square_hitbox_hit_by_bullet();

    bool square_hitbox_hit_by_beam();

    bool circle_hitbox_hit_by_bullet();

    bool circle_hitbox_hit_by_beam();
	~HitBox();
};