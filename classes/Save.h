//
// Created by leo duan on 2019/4/7.
//

#ifndef PLANE_BATTLE_SAVE_H
#define PLANE_BATTLE_SAVE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
#include "json.hpp"

using json=nlohmann::json;

class Save
{
private:
    std::string filename;
public:
    Save();
    void getPlaneInfo();
    void getEnemyInfo();
    void getLevelInfo(int levelnum,int enemynum);
    std::map<std::string,int> planeInfo;
    std::array<bool,4> movemode;
    std::string textureName;
    double spawnTime;
};


#endif //PLANE_BATTLE_SAVE_H
