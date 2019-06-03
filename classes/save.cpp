#include <utility>

#include <utility>

//
// Created by leo duan on 2019/4/7.
//

#include "save.h"

save::save()
{
    filename = "save.json";
}

void save::getinfo()
{
    getplaneinfo();
}

void save::getplaneinfo()
{
    std::ifstream isave(filename);
    json jsave;
    isave >> jsave;
    std::string max_health = std::to_string(jsave.at("plane").at("max_health").get<int>());
    std::string health = std::to_string(jsave.at("plane").at("health").get<int>());
    std::string speed = std::to_string(jsave.at("plane").at("speed").get<int>());
    std::string position_x = std::to_string(jsave.at("plane").at("position_x").get<int>());
    std::string position_y = std::to_string(jsave.at("plane").at("position_y").get<int>());
    std::string texture_name = jsave.at("plane").at("texture_name").get<std::string>();
    std::string weapon_name = jsave.at("plane").at("weapon_name").get<std::string>();
    std::string LastMove = std::to_string(jsave.at("plane").at("LastMove").get<int>());
    planeinfo["max_health"] = max_health;
    planeinfo["health"] = health;
    planeinfo["speed"] = speed;
    planeinfo["position_x"] = position_x;
    planeinfo["position_y"] = position_y;
    planeinfo["texture_name"] = texture_name;
    planeinfo["weapon_name"] = weapon_name;
    planeinfo["LastMove"] = LastMove;
}

void save::getenemyinfo()
{
    std::ifstream isave(filename);
    json jsave;
    isave >> jsave;
    std::string max_health = std::to_string(jsave.at("enemy").at("max_health").get<int>());
    std::string health = std::to_string(jsave.at("enemy").at("health").get<int>());
    std::string speed = std::to_string(jsave.at("enemy").at("speed").get<int>());
    std::string position_x = std::to_string(jsave.at("enemy").at("position_x").get<int>());
    std::string position_y = std::to_string(jsave.at("enemy").at("position_y").get<int>());
    std::string texture_name = jsave.at("enemy").at("texture_name").get<std::string>();
    std::string weapon_name = jsave.at("enemy").at("weapon_name").get<std::string>();
    std::string LastMove = std::to_string(jsave.at("enemy").at("LastMove").get<int>());
    planeinfo["max_health"] = max_health;
    planeinfo["health"] = health;
    planeinfo["speed"] = speed;
    planeinfo["position_x"] = position_x;
    planeinfo["position_y"] = position_y;
    planeinfo["texture_name"] = texture_name;
    planeinfo["weapon_name"] = weapon_name;
    planeinfo["LastMove"] = LastMove;
}

