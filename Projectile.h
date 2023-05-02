//This class alongside Environment, is used to demo the MyTuple class

#include "MyTuple.h"
#pragma once

class Projectile {
private:
	MyTuple position; // point
	MyTuple velocity; // vector

public:
	Projectile(MyTuple position, MyTuple velocity) : position(position), velocity(velocity) {}

	MyTuple getPosition() const {
		return position;
	}

	MyTuple getVelocity() const {
		return velocity;
	}

	friend std::ostream& operator<<(std::ostream& os, const Projectile& t);
};


