#include "Plane.h"

Plane::Plane(HitBox *hitbox, Window *window, Save& save) : firing(false), lastFire(0)
{
    this->maxHealth = save.planeInfo["max_health"];
    this->health = save.planeInfo["max_health"];
    this->speed = save.planeInfo["speed"];
    this->hitbox = hitbox;
    this->position.x = save.planeInfo["position_x"];
    this->position.y = save.planeInfo["position_y"];
    this->texture = window->loadPicture(save.textureName);
    this->window = window;
    this->weapon = new Weapon((BULLET));
    this->lastMove = SDL_GetTicks();


    position.w = 164;
    position.h = 182;
    fireOriginPosition.x = position.x + 150;
    fireOriginPosition.y = position.y + 80;

    //SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}
Plane::Plane(int max_health, int speed, HitBox *hitbox, int coordinate_x, int coordinate_y,
             const std::string &texture_name, Window *window) : firing(false), lastFire(0)
{
	this->maxHealth = max_health;
	this->health = max_health;
	this->speed = speed;
	this->hitbox = hitbox;
	this->position.x = coordinate_x;
	this->position.y = coordinate_y;
	this->texture = window->loadPicture(texture_name);
	this->window = window;
	this->weapon = new Weapon(BULLET);
	this->lastMove = SDL_GetTicks();

	position.w = 164;
	position.h = 182;
	fireOriginPosition.x = position.x + 150;
	fireOriginPosition.y = position.y + 80;
}

Plane::Plane(int max_health, int speed, HitBox *hitbox,
             const std::string &texture_name, Window *window) : hitbox(hitbox)
{
	this->maxHealth = max_health;
	this->health = max_health;
	this->speed = speed;
	//this->hitbox = hitbox;
	this->position.x = SDL_WINDOWPOS_CENTERED;
	this->position.y = SDL_WINDOWPOS_CENTERED;
	this->texture = window->loadPicture(texture_name);
	this->window = window;
	this->lastMove = SDL_GetTicks();
	SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}

bool Plane::damage(int damage_amount)
{
	health -= damage_amount;

	return health < 0;
}

void Plane::spawn()
{
	SDL_RenderCopy(window->getRenderer(), texture, nullptr, &position);
}

void Plane::move()
{
	double timeLength = 0.001 * (SDL_GetTicks() - lastMove);

	if (moving[0] && position.y >= 10)
	{
		moveTemp.second -= speed * timeLength;
	}
	if (moving[1] && position.y <= 720)
	{
		moveTemp.second += speed * timeLength;
	}
	if (moving[2] && position.x >= 0)
	{
		moveTemp.first -= speed * timeLength;
	}
	if (moving[3] && position.x <= 1280)
	{
		moveTemp.first += speed * timeLength;
	}

	if (std::abs(moveTemp.first) > 1)
	{
		position.x += (int) std::trunc(moveTemp.first);
		moveTemp.first -= std::trunc(moveTemp.first);
	}

	if (std::abs(moveTemp.second) > 1)
	{
		position.y += (int) std::trunc(moveTemp.second);
		moveTemp.second -= std::trunc(moveTemp.second);
	}

	lastMove = SDL_GetTicks();
}

void Plane::change_weapon(Weapon weapon)
{
}

void Plane::fire(std::deque<Bullet> &playerBullets)
{
	lastFire = SDL_GetTicks();
	playerBullets.push_back(weapon->fire(window, window->loadPicture("playerBullet.png"), &fireOriginPosition));
}

void Plane::refresh()
{
	move();
	hitbox->set_x(position.x + position.w / 2);
	hitbox->set_y(position.y + position.h / 2);
	fireOriginPosition.x = position.x + 100;
	fireOriginPosition.y = position.y + 86;
	/*if ( firing && SDL_GetTicks() - lastFire > weapon->get_fire_interval() * 1000 )
	{
		std::cout << "fire at" << SDL_GetTicks() << std::endl;
	}*/

	showImage();
}

void Plane::showImage()
{
	SDL_RenderCopyEx(window->getRenderer(), texture, nullptr, &position, 0, nullptr, SDL_FLIP_NONE);
}

void Plane::keyDownEvent(SDL_Keycode sym)
{
	switch (sym)
	{
		case SDLK_UP:
			moving[0] = true;
			moving[1] = false;
			break;
		case SDLK_DOWN:
			moving[1] = true;
			moving[0] = false;
			break;
		case SDLK_LEFT:
			moving[2] = true;
			moving[3] = false;
			break;
		case SDLK_RIGHT:
			moving[3] = true;
			moving[2] = false;
			break;
		case SDLK_SPACE:
			firing = true;
		default:
			break;
	}
}

void Plane::keyUpEvent(SDL_Keycode sym)
{
	switch (sym)
	{
		case SDLK_UP:
			moving[0] = false;
			break;
		case SDLK_DOWN:
			moving[1] = false;
			break;
		case SDLK_LEFT:
			moving[2] = false;
			break;
		case SDLK_RIGHT:
			moving[3] = false;
			break;
		case SDLK_SPACE:
			firing = false;
		default:
			break;
	}
}

Plane::~Plane()
{
	//weapon.release();
	//hitbox.release();
}