//This class alongside Environment, is used to demo the Tuple class

#include "Tuple.h"
#pragma once

class Projectile {
private:
	Tuple position; // point
	Tuple velocity; // vector

public:
	Projectile(Tuple position, Tuple velocity) : position(position), velocity(velocity) {}

	Tuple getPosition() const {
		return position;
	}

	Tuple getVelocity() const {
		return velocity;
	}

	// void setX(float x) {
   //  this->x = x;

	void setPosition(Tuple pos) {
		position = pos;
	}
	void setVelocity(Tuple vel) {
		velocity = vel;
	}
	friend std::ostream& operator<<(std::ostream& os, const Projectile& t);

};


