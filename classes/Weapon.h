#pragma once
class Weapon
{
private:
    enum category_list{bullet, beam};
    category_list category;
public:
	Weapon();

	~Weapon();
};