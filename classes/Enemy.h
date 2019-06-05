#pragma once

#include "Plane.h"
#include <utility>
#include <string>



class Enemy :
        public Plane
{
public:
    double lastMove;
    double parameter;
    double sinMoveTemp;
    std::pair<double, double> lineMoveTemp;

    SDL_Rect originPosition;

    Enemy()= default;
    Enemy(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
          const std::string &texture_name, Window *window);

    void spawn() override;

    void move() override;

    //刷新状态及贴图
    void refresh() override;

    //周期运动
    void MoveAsSin(int amplitude, double period);

    //周期移动默认值
    void MoveAsSin();

    void MoveAsParabola(double a, double v, double c);

    void MoveAsCircle(int radius);

    //直线移动
    //参数为极坐标下θ,单位为Π
    void MoveAsLine(double direction);
    void MoveAsLine();

    ~Enemy();
};