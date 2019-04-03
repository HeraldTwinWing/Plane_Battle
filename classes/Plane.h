#pragma once
#include <string>
#include "HitBox.h"
#include "Weapon.h"

class Plane
{
private:
	//生命值
	int max_health;
	int health;

	//移动速度
	int speed;

	//武器种类
	Weapon weapon;

	//击中判定点
	HitBox hitboxs;

	//坐标
	int coordinate_x;
	int coordinate_y;

public:
	Plane();
	//生成单位
	void spawn();

	/*控制飞船移动
	 * 该方法输入移动方向(按键)
	 * 根据速度控制飞船坐标向该方向改变
	 * */
	void move(int direction);

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