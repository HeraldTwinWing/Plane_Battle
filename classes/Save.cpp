#include <utility>

//
// Created by leo duan on 2019/4/7.
//

#include "Save.h"

Save::Save()
{
	filename = "../save/save.json";
}

void Save::getinfo()
{
	getPlaneInfo();
}

void Save::getPlaneInfo()
{
	std::ifstream iSave(filename);
	json jSave;
	iSave >> jSave;
	int max_health = jSave.at("plane").at("max_health").get<int>();
	int health = jSave.at("plane").at("health").get<int>();
	int speed = jSave.at("plane").at("speed").get<int>();
	int position_x = jSave.at("plane").at("position_x").get<int>();
	int position_y = jSave.at("plane").at("position_y").get<int>();
	std::string texture_name = jSave.at("plane").at("textureName").get<std::string>();
	int weapon_num = jSave.at("plane").at("weapon_num").get<int>();
	//std::string LastMove = std::to_string(jSave.at("plane").at("LastMove").get<int>());
	planeInfo["max_health"] = max_health;
	planeInfo["health"] = health;
	planeInfo["speed"] = speed;
	planeInfo["position_x"] = position_x;
	planeInfo["position_y"] = position_y;
	this->textureName = texture_name;
	planeInfo["weapon_num"] = weapon_num;
	//planeInfo["LastMove"] = LastMove;
}

void Save::getEnemyInfo()
{
	std::ifstream iSave(filename);
	json jSave;
	iSave >> jSave;
	int max_health = jSave.at("Enemy").at("max_health").get<int>();
	int health = jSave.at("Enemy").at("health").get<int>();
	int speed = jSave.at("Enemy").at("speed").get<int>();
	int position_x = jSave.at("Enemy").at("position_x").get<int>();
	int position_y = jSave.at("Enemy").at("position_y").get<int>();
	std::string texture_name = jSave.at("Enemy").at("textureName").get<std::string>();
	int weapon_num = jSave.at("Enemy").at("weapon_num").get<int>();
	//int LastMove = jSave.at("Enemy").at("LastMove").get<int>();
	planeInfo["max_health"] = max_health;
	planeInfo["health"] = health;
	planeInfo["speed"] = speed;
	planeInfo["position_x"] = position_x;
	planeInfo["position_y"] = position_y;
	this->textureName = texture_name;
	planeInfo["weapon_num"] = weapon_num;
	//planeInfo["LastMove"] = LastMove;
}

void Save::getLevelOneInfo(int levelnum,int enemynum)
{
	std::ifstream iSave(filename);
	json jSave;
	iSave >> jSave;
	int max_health = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("max_health").get<int>();
	int health = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("health").get<int>();
	int speed = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("speed").get<int>();
	int position_x = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("position_x").get<int>();
	int position_y = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("position_y").get<int>();
	std::string texture_name = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("textureName").get<std::string>();
	int weapon_num = jSave.at("Level"+std::to_string(levelnum)).at("Enemy"+std::to_string(enemynum)).at("weapon_num").get<int>();
	//int LastMove = jSave.at("Level1"+std::to_string(levelnum)).at("Enemy").at("LastMove").get<int>();
	planeInfo["max_health"] = max_health;
	planeInfo["health"] = health;
	planeInfo["speed"] = speed;
	planeInfo["position_x"] = position_x;
	planeInfo["position_y"] = position_y;
	this->textureName = texture_name;
	planeInfo["weapon_num"] = weapon_num;
	//planeInfo["LastMove"] = LastMove;
}
