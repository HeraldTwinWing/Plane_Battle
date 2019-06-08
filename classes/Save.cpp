#include <utility>

//
// Created by leo duan on 2019/4/7.
//

#include "Save.h"

Save::Save()
{
    filename = "../save/save.json";
}


void Save::getPlaneInfo()
{
    std::ifstream iSave(filename);
    json jSave;
    iSave >> jSave;
    planeInfo["max_health"] = jSave.at("plane").at("max_health").get<int>();
    planeInfo["health"] = jSave.at("plane").at("health").get<int>();
    planeInfo["speed"] = jSave.at("plane").at("speed").get<int>();
    planeInfo["position_x"] = jSave.at("plane").at("position_x").get<int>();
    planeInfo["position_y"] = jSave.at("plane").at("position_y").get<int>();
    this->textureName = jSave.at("plane").at("textureName").get<std::string>();
    planeInfo["weapon_num"] = jSave.at("plane").at("weapon_num").get<int>();
    //planeInfo["LastMove"] = jSave.at("plane").at("LastMove").get<int>();
}

void Save::getEnemyInfo()
{
    std::ifstream iSave(filename);
    json jSave;
    iSave >> jSave;
    planeInfo["max_health"] = jSave.at("Enemy").at("max_health").get<int>();
    planeInfo["health"] = jSave.at("Enemy").at("health").get<int>();
    planeInfo["speed"] = jSave.at("Enemy").at("speed").get<int>();
    planeInfo["position_x"] = jSave.at("Enemy").at("position_x").get<int>();
    planeInfo["position_y"] = jSave.at("Enemy").at("position_y").get<int>();
    this->textureName = jSave.at("Enemy").at("textureName").get<std::string>();
    planeInfo["weapon_num"] = jSave.at("Enemy").at("weapon_num").get<int>();
    //planeInfo["LastMove"] = jSave.at("Enemy").at("LastMove").get<int>();
}

void Save::getLevelInfo(int levelnum,int enemynum)
{
    std::ifstream iSave(filename);
    json jSave;
    iSave >> jSave;
    planeInfo["max_health"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("max_health").get<int>();
    planeInfo["health"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("health").get<int>();
    planeInfo["speed"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("speed").get<int>();
    planeInfo["position_x"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("position_x").get<int>();
    planeInfo["position_y"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("position_y").get<int>();
    this->textureName = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("textureName").get<std::string>();
    planeInfo["weapon_num"] =jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("weapon_num").get<int>();
    bool movemode_line = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("movemode_line").get<bool>();
    bool movemode_sin = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("movemode_sin").get<bool>();
    bool movemode_parabola = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("movemode_parabola").get<bool>();
    bool movemode_circle = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("movemode_circle").get<bool>();
    planeInfo["LastMove"] = jSave.at("Level1").at("Enemy"+std::to_string(levelnum)).at("LastMove").get<int>();
    planeInfo["sinMoveAmplitude"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("sinMoveAmplitude").get<int>();
    planeInfo["sinMovePeriod"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("sinMovePeriod").get<int>();
    planeInfo["parabolaMoveA"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("parabolaMoveA").get<int>();
    planeInfo["parabolaMoveB"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("parabolaMoveB").get<int>();
    planeInfo["parabolaMoveC"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("parabolaMoveC").get<int>();
    planeInfo["circleMoveCenter_x"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("circleMoveCenter_x").get<int>();
    planeInfo["circleMoveCenter_y"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("circleMoveCenter_y").get<int>();
    planeInfo["circleMoveRadius"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("circleMoveRadius").get<int>();
    this->spawnTime = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("spawnTime").get<double>();
    planeInfo["Height"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("Height").get<int>();
    planeInfo["Width"] = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("Width").get<int>();
    movemode = {movemode_line,movemode_sin,movemode_parabola,movemode_circle};

}

