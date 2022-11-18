#pragma once
class gameobject {

protected: 
	float pos_x;
	float pos_y;
	int position;
public:

	virtual void draw() = 0;
	virtual bool contains(float x, float y) = 0;


};