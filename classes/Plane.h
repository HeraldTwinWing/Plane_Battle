#pragma once
#include <string>
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

public:
	Plane();
	//���ɵ�λ
	void spawn();

	/*���Ʒɴ��ƶ�
	 * �÷��������ƶ�����(����)
	 * �����ٶȿ��Ʒɴ�������÷���ı�
	 * */
	void move(int direction);

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