
//This class alongside Projectile, is used to demo the MyTuple class

#include "MyTuple.h"
#pragma once


class Environment {
private:
	MyTuple gravity, wind; // both vectors

public:
	Environment(MyTuple gravity, MyTuple wind) : gravity(gravity), wind(wind) {}
	
	MyTuple getGravity() const {
		return gravity;
	}
	MyTuple getWind() const {
		return wind;
	}
};

