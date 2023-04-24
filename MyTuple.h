#include <iostream>
#include <string>
#include <cmath>
//#include "MyTuple.h"

class MyTuple {
private:
	float x, y, z;
	int w;
	static constexpr float EPSILON = 0.00001f;
public:
	MyTuple() : x(0), y(0), z(0), w(w == 0 ? 0 : 1) {}
	MyTuple(float x, float y, float z, int w) {
		this->x = x;
		this->y = y;
		this->z = z;
		if (w == 0) { // needs to be either point or vector
			this->w = 0;
		}
		else {
			this->w = 1;
		}
	}

	friend MyTuple operator-(const MyTuple& t1, const MyTuple& t2);
	friend MyTuple operator+(const MyTuple& t1, const MyTuple& t2);
	bool equal(MyTuple t2);

	float getX() const {
		return x;
	}
	float getY() const {
		return y;
	}
	float getZ() const {
		return z;
	}
	int getW() const {
		return w;
	}

	void setX(float x) {
		this->x = x;
	}
	void setY(float y) {
		this->y = y;
	}
	void setZ(float z) {
		this->z = z;
	}
	void setW(int w) {
		this->w = w;
	}


	std::string tupleType() {
		if (this->getW() == 0) {
			return "vector";
		}
		else {
			return "point";
		}
	}

};
