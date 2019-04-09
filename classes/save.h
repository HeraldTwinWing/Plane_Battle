//
// Created by leo duan on 2019/4/7.
//

#ifndef PLANE_BATTLE_SAVE_H
#define PLANE_BATTLE_SAVE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "json.hpp"

using json=nlohmann::json;

class save
{
private:
    std::string filename;
    std::string nameOfClass;
    std::string nameOfEntity;
public:
    save(std::string classname,std::string name);
    int getxcoordinate();
    int getycoordinate();
    int getmaxhealth();
    int getspeed();
    std::string gettexturename();
    void writexcoordinate();
    void writexcoordinate();
    void writemaxhealth();
    void writespeed();
    void writetexturename();

};


#endif //PLANE_BATTLE_SAVE_H
