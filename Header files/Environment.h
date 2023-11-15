
//This class alongside Projectile, is used to demo the Tuple class

#include "Tuple.h"
#pragma once


class Environment {
private:
	Tuple gravity, wind; // both vectors

public:
	Environment(Tuple gravity, Tuple wind) : gravity(gravity), wind(wind) {}
	
	Tuple getGravity() const {
		return gravity;
	}
	Tuple getWind() const {
		return wind;
	}
};

