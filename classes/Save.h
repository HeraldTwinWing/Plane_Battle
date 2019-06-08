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
    void getinfo();
    void getPlaneInfo();
    void getEnemyInfo();
    void getLevelOneInfo(int levelnum,int enemynum);
    std::map<std::string,int> planeInfo;
    std::string textureName;

};


#endif //PLANE_BATTLE_SAVE_H
