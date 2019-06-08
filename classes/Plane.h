#pragma once

#include <string>
#include <utility>
#include <memory>
#include <deque>
//#include <map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "HitBox.h"
#include "Save.h"

class Plane
{
public:
	//����ֵ
	int maxHealth;
	int health;

	//�ƶ��ٶ�
	int speed;
	//�������ҵ��ƶ�״̬
	bool moving[4] = {false, false, false, false};
	double lastMove;
	std::pair<double, double> moveTemp;

	//��������
	//std::unique_ptr<Weapon> weapon;
	Weapon* weapon;
	bool firing;
	double lastFire;

	//�����ж���
	//std::unique_ptr<HitBox> hitbox;
	HitBox* hitbox;
	std::pair<int, int> hitboxRelativePosition;

	//�������С
	SDL_Rect position;
	SDL_Point fireOriginPosition;

	SDL_Texture *texture = nullptr;

	//�������
	//std::map<std::string,int> jsonMap;
	//�ɻ����ڵ���Ⱦ��[ͼ��]
	Window *window = nullptr;

    Plane(HitBox *hitbox, Window *window, Save &save);

	Plane(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
	      const std::string &texture_name, Window *window);

	Plane(int max_health, int speed, HitBox *hitbox,
	      const std::string &texture_name, Window *window);

	virtual ~Plane();


	//���ɵ�λ
	virtual void spawn();

	/*���Ʒɴ��ƶ�
	 * �÷��������ƶ�����(����)
	 * �����ٶȿ��Ʒɴ�������÷���ı�
	 * */
	virtual void move();


	/*�ܵ��˺�k
	 * �����˺������۳���Ӧ��������ֵ
	 * �۳�������ֵ����0����false�����򷵻�true
	 * */
	virtual bool damage(int damage_amount);

	/*�л�����
	 * ʰȡ������ı䵱ǰ��������
	 * */
	void change_weapon(Weapon weapon);

	/*���
	 * �����������ഴ���ӵ����󲢴���GameData::playerBullets
	 * */
	virtual void fire(std::deque<Bullet> &playerBullets);

	//ˢ�¸ö���״̬
	//������ͼλ����hitboxλ��
	virtual void refresh();

	virtual void showImage();

	//��������ҷɻ���ص��¼�
	void keyDownEvent(SDL_Keycode sym);

	void keyUpEvent(SDL_Keycode sym);

	bool if_firing()
	{
		return firing;
	}

	virtual bool if_not_in_fire_CD()
	{
		return SDL_GetTicks() - lastFire > weapon->get_fire_interval() * 1000;
	}

};