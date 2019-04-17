#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "HitBox.h"

class Plane
{
public:
	//����ֵ
	int max_health;
	int health;

	//�ƶ��ٶ�
	int speed;
	//�������ҵ��ƶ�״̬
	bool moving[4] = {false, false, false, false};

	//��������
	Weapon *weapon;
	bool firing;
	double last_fire;

	//�����ж���
	HitBox *hitbox;

	//�������С
	SDL_Rect position;

	SDL_Texture *texture = nullptr;

	//�ɻ����ڵ���Ⱦ��[ͼ��]
	Window *window = nullptr;

	Plane(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
	      const std::string &texture_name, Window *window);

	Plane(int max_health, int speed, HitBox *hitbox,
	      const std::string &texture_name, Window *window);

	Plane(Plane &plane);

	Plane();

	//���ɵ�λ
	void spawn();

	/*���Ʒɴ��ƶ�
	 * �÷��������ƶ�����(����)
	 * �����ٶȿ��Ʒɴ�������÷���ı�
	 * */
	virtual void move();


	/*�ܵ��˺�
	 * �����˺������۳���Ӧ��������ֵ
	 * �۳�������ֵ����0����true�����򷵻�false
	 * */
	bool damage(int damage_amount);

	/*�л�����
	 * ʰȡ������ı䵱ǰ��������
	 * */
	void change_weapon(Weapon weapon);

	/*���
	 * �����������ഴ����Ӧ���ӵ�����
	 * */
	Bullet fire();

	//ˢ�¸ö���״̬
	//������ͼλ����hitboxλ��
	void refresh();

	//��������ҷɻ���ص��¼�
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