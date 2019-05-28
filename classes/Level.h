#pragma once

#include <utility>
#include <queue>
#include "GameData.h"

class Level
{
public:
    std::queue<std::pair<double, EnemyType>> levelInfo;
    //��ʼ��ǰ�ؿ���ʱ��
    double startTime;

    /* ���ܣ����ݵ�ǰ�ؿ���ȡ�ļ��б���Ĺؿ���Ϣ��������levelInfo��Ա
     *       �õ�ǰʱ���ʼ��startTime
     * ������level:��ǰ�ؿ�
     * */
    Level(int level);

    /* ���ܣ����ݵ�ǰʱ����ؿ���ʼʱ���ʱ������ɵз���λ
     * ����ֵ�����ɵ�λ����true��δ���ɷ���false;
     * */
    bool UnitSpawn();

    ~Level();
};

