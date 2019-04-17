#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "HitBox.h"

class Plane
{
public:
	//生命值
	int max_health;
	int health;

	//移动速度
	int speed;
	//上下左右的移动状态
	bool moving[4] = {false, false, false, false};

	//武器种类
	Weapon *weapon;
	bool firing;
	double last_fire;

	//击中判定点
	HitBox *hitbox;

	//坐标与大小
	SDL_Rect position;

	SDL_Texture *texture = nullptr;

	//飞机所在的渲染器[图层]
	Window *window = nullptr;

	Plane(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
	      const std::string &texture_name, Window *window);

	Plane(int max_health, int speed, HitBox *hitbox,
	      const std::string &texture_name, Window *window);

	Plane(Plane &plane);

	Plane();

	//生成单位
	void spawn();

	/*控制飞船移动
	 * 该方法输入移动方向(按键)
	 * 根据速度控制飞船坐标向该方向改变
	 * */
	virtual void move();


	/*受到伤害
	 * 输入伤害量，扣除相应量的生命值
	 * 扣除后生命值大于0返回true，否则返回false
	 * */
	bool damage(int damage_amount);

	/*切换武器
	 * 拾取武器后改变当前武器种类
	 * */
	void change_weapon(Weapon weapon);

	/*射击
	 * 根据武器种类创建相应的子弹对象
	 * */
	Bullet fire();

	//刷新该对象状态
	//包括贴图位置与hitbox位置
	void refresh();

	//处理与玩家飞机相关的事件
	void keyDownEvent(SDL_Keycode sym);
	void keyUpEvent(SDL_Keycode sym);

	bool if_firing()
	{
		return firing;
	}

	bool if_not_in_fire_CD()
	{
		return SDL_GetTicks() - last_fire > weapon->get_fire_interval() * 1000;
	}
};