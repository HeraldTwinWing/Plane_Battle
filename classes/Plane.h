#pragma once
#include <string>
#include "SDL2/SDL.h"
#include "HitBox.h"

class Plane
{
private:
	//����ֵ
	int max_health;
	int health;

	//�ƶ��ٶ�
	int speed;

	//��������
	std::string weapon_category;

	//�����ж���
	HitBox hitboxs;

	//����
	int coordinate_x;
	int coordinate_y;

	std::string texture_name;
public:
	Plane(int max_health, int speed, HitBox hitbox, int coordinate_x, int coordinate_y, std::string texture_name);
	Plane(int max_health, int speed, HitBox hitbox, std::string texture_name);
	Plane(Plane &plane);

	//���ɵ�λ
	void spawn();

	/*���Ʒɴ��ƶ�
	 * �÷��������ƶ�����(����)
	 * �����ٶȿ��Ʒɴ�������÷���ı�
	 * */
	void move(SDL_Event &key);

	/*�ܵ��˺�
	 * �����˺������۳���Ӧ��������ֵ
	 * �۳�������ֵ����0����true�����򷵻�false
	 * */
	bool damage(int damage_amount);

	/*�л�����
	 * ʰȡ������ı䵱ǰ��������
	 * */
	void change_weapon(std::string weapon_category);

	/*���
	 * �����������ഴ����Ӧ���ӵ�����
	 * */
	void shoot();
	~Plane();
};