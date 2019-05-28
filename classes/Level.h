#pragma once

#include <utility>
#include <queue>
#include "GameData.h"

class Level
{
public:
    std::queue<std::pair<double, EnemyType>> levelInfo;
    //开始当前关卡的时间
    double startTime;

    /* 功能：根据当前关卡读取文件中保存的关卡信息并保存至levelInfo成员
     *       用当前时间初始化startTime
     * 参数：level:当前关卡
     * */
    Level(int level);

    /* 功能：根据当前时间与关卡开始时间的时间差生成敌方单位
     * 返回值：生成单位返回true，未生成返回false;
     * */
    bool UnitSpawn();

    ~Level();
};

