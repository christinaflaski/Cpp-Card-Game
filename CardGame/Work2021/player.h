#pragma once
#include "defines.h"
#include "gameobject.h"
#include "cards.h"
#include <string>

class Player : public gameobject
{
	float m_oriantation;

	bool m_highlighted = false;
	bool m_active = false;

	int life_points = 0;
	int defence = 0;
	int attack = 0;


public:
	void draw() override;

	void addstatistics(int a, int b, int i);

	float getAttack() { return attack; }
	float getDefence() { return defence; }
	float getLifepoints() { return life_points; }
	float getPosX() { return pos_x; }
	float getPosY() { return pos_y; }
	void setPosX(float x) { pos_x = x; }
	void setPosY(float y) { pos_y = y; }
	void setPosition(int p) { position = p; }
	int getPosition() { return position; }

	void setHighlight(bool h) { m_highlighted = h; }
	void setActive(bool a) { m_active = a; }
	bool getActive() { return m_active; }

	void setAttack(int at) { attack = at; }
	void setDefence(int d) { defence = d; }
	void setLifepoint(int l) { life_points = l; }
	void attacking(Player* p1, int att);
	
	
	
	bool contains(float x, float y) override;
	Player(float x, float y, int i);
	~Player();
};
