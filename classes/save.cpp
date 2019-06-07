#include <utility>

#include <utility>

//
// Created by leo duan on 2019/4/7.
//

#include "Save.h"

Save::Save()
{
    filename = "save.json";
}

void Save::getinfo()
{
    getplaneinfo();
}

void Save::getplaneinfo()
{
    std::ifstream isave(filename);
    json jsave;
    isave >> jsave;
    int max_health = jsave.at("plane").at("max_health").get<int>();
    int health = jsave.at("plane").at("health").get<int>();
    int speed = jsave.at("plane").at("speed").get<int>();
    int position_x = jsave.at("plane").at("position_x").get<int>();
    int position_y = jsave.at("plane").at("position_y").get<int>();
    std::string texture_name = jsave.at("plane").at("texture_name").get<std::string>();
    //std::string weapon_name = jsave.at("plane").at("weapon_name").get<std::string>();
    //std::string LastMove = std::to_string(jsave.at("plane").at("LastMove").get<int>());
    planeinfo["max_health"] = max_health;
    planeinfo["health"] = health;
    planeinfo["speed"] = speed;
    planeinfo["position_x"] = position_x;
    planeinfo["position_y"] = position_y;
    this->texture_name = texture_name;
    //planeinfo["weapon_name"] = weapon_name;
    //planeinfo["LastMove"] = LastMove;
}

void Save::getenemyinfo()
{
    std::ifstream isave(filename);
    json jsave;
    isave >> jsave;
    int max_health = jsave.at("Enemy").at("max_health").get<int>();
    int health = jsave.at("Enemy").at("health").get<int>();
    int speed = jsave.at("Enemy").at("speed").get<int>();
    int position_x = jsave.at("Enemy").at("position_x").get<int>();
    int position_y = jsave.at("Enemy").at("position_y").get<int>();
    std::string texture_name = jsave.at("Enemy").at("texture_name").get<std::string>();
    //std::string weapon_name = jsave.at("Enemy").at("weapon_name").get<std::string>();
    //int LastMove = jsave.at("Enemy").at("LastMove").get<int>();
    planeinfo["max_health"] = max_health;
    planeinfo["health"] = health;
    planeinfo["speed"] = speed;
    planeinfo["position_x"] = position_x;
    planeinfo["position_y"] = position_y;
    this->texture_name = texture_name;
    //planeinfo["weapon_name"] = weapon_name;
    //planeinfo["LastMove"] = LastMove;
}

