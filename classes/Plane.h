#pragma once
#include <string>
#include "SDL2/SDL.h"
#include "HitBox.h"

class Plane
{
private:
	//生命值
	int max_health;
	int health;

	//移动速度
	int speed;

	//武器种类
	std::string weapon_category;

	//击中判定点
	HitBox hitboxs;

	//坐标
	int coordinate_x;
	int coordinate_y;

	std::string texture_name;
public:
	Plane(int max_health, int speed, HitBox hitbox, int coordinate_x, int coordinate_y, std::string texture_name);
	Plane(int max_health, int speed, HitBox hitbox, std::string texture_name);
	Plane(Plane &plane);

	//生成单位
	void spawn();

	/*控制飞船移动
	 * 该方法输入移动方向(按键)
	 * 根据速度控制飞船坐标向该方向改变
	 * */
	void move(SDL_Event &key);

	/*受到伤害
	 * 输入伤害量，扣除相应量的生命值
	 * 扣除后生命值大于0返回true，否则返回false
	 * */
	bool damage(int damage_amount);

	/*切换武器
	 * 拾取武器后改变当前武器种类
	 * */
	void change_weapon(std::string weapon_category);

	/*射击
	 * 根据武器种类创建相应的子弹对象
	 * */
	void shoot();
	~Plane();
};