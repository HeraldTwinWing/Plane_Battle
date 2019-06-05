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

    //ˢ��״̬����ͼ
    void refresh() override;

    //�����˶�
    void MoveAsSin(int amplitude, double period);

    //�����ƶ�Ĭ��ֵ
    void MoveAsSin();

    void MoveAsParabola(double a, double v, double c);

    void MoveAsCircle(int radius);

    //ֱ���ƶ�
    //����Ϊ�������¦�,��λΪ��
    void MoveAsLine(double direction);
    void MoveAsLine();

    ~Enemy();
};