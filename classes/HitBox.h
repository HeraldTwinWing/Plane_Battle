#pragma once

#include <string>
#include "Weapon.h"


class HitBox
{
public:


    //Hitbox 中心坐标
    int center_x;
    int center_y;
    int radius;

    std::string category;

    explicit HitBox(std::string category);

    /*击中判定
     * 根据hitbox种类与武器种类的不同
     * 选择对应的判定方法
     * 击中返回true,否则返回false
     * */
    bool ifBulletHit(Bullet *bullet);

    bool square_hitbox_hit_by_bullet();

    bool square_hitbox_hit_by_beam();

    bool circle_hitbox_hit_by_bullet();

    bool circle_hitbox_hit_by_beam();

    void set_x(int x);
    void set_y(int y);
    ~HitBox();
};