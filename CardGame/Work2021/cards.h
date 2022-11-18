#pragma once
#include "defines.h"
#include "gameobject.h"
#include "player.h"


class Cards : public gameobject
{
	float m_oriantation;
	int positive = (rand() % 9) + 2;
	int negative = (rand() % 10) + 1;
	int x = (rand() % 9) + 2;
	int n = (rand() % 9) + 2;
	
	

	bool m_highlighted_card = false;
	bool m_active_card = false;

public:
	
	void draw() override;

	int getPositive() { return positive; }
	int getNegative() { return negative; }
	void setPositive(int p) { positive = p; }
	void setNegative(int n) { negative = n; }
	float getPosX() { return pos_x; }
	float getPosY() { return pos_y; }
	void setPosX(float x) { pos_x = x; }
	void setPosY(float y) { pos_y = y; }
	void setPosition(int p) { position = p; }
	int getPosition() { return position; }

	void setHighlightCard(bool hc) { m_highlighted_card = hc; }
	void setActiveCard(bool ac) { m_active_card = ac; }
	int changepositive();
	int changenegative(Cards* card, int a, int d, int l);
	bool contains(float x, float y) override;

	Cards(float x, float y, int i);
	~Cards();
	
	
	
};

