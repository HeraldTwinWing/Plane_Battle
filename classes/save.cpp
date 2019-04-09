#include <utility>

#include <utility>

//
// Created by leo duan on 2019/4/7.
//

#include "save.h"

save::save(std::string classname,std::string name)
{
    filename = "save.json";
    nameOfClass = std::move(classname);
    nameOfEntity = std::move(name);
}

int save::getxcoordinate()
{
    std::ifstream isave("save.json");
    json jsave;
    isave >> jsave;
    return jsave.at(nameOfClass).at(nameOfEntity).at("x").get<int>();
}

int save::getycoordinate()
{
    std::ifstream isave("save.json");
    json jsave;
    isave >> jsave;
    return jsave.at(nameOfClass).at(nameOfEntity).at("y").get<int>();
}

int save::getmaxhealth()
{
    std::ifstream isave("save.json");
    json jsave;
    isave >> jsave;
    return jsave.at(nameOfClass).at(nameOfEntity).at("max_health").get<int>();
}

int save::getspeed()
{
    std::ifstream isave("save.json");
    json jsave;
    isave >> jsave;
    return jsave.at(nameOfClass).at(nameOfEntity).at("speed").get<int>();
}

std::string save::gettexturename()
{
    std::ifstream isave("save.json");
    json jsave;
    isave >> jsave;
    return jsave.at(nameOfClass).at(nameOfEntity).at("texture_name").get<std::string>();
}
