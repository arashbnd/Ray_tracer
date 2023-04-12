#include <iostream>
#include <string>
#include <cmath>

class MyTuple {
private:
	float x, y, z, w;
	static constexpr float EPSILON = 0.00001f;
public:
	MyTuple(): x(0), y(0), z(0), w(	w == 0 ? 0 : 1) {}
	MyTuple(float x, float y, float z, float w) {
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
	bool equal(MyTuple t1, MyTuple t2);
	
	float getX() const{
		return x;
	}
	float getY() const{
		return y;
	}
	float getZ() const{
		return z;
	}
	float getW() const{
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
	void setW(float w) {
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


MyTuple operator-(const MyTuple& t1, const MyTuple& t2) {
	// the value of w, needs to be either 1 or 0
	if (t1.getW() - t2.getW() < 0) {
		return MyTuple(t1.getX() - t2.getX(), t1.getY() - t2.getY(), t1.getZ() - t2.getZ(), 0);
	}
	return MyTuple(t1.getX() - t2.getX(), t1.getY() - t2.getY(), t1.getZ() - t2.getZ(), t1.getW() - t2.getW());
}

MyTuple operator+(const MyTuple& t1, const MyTuple& t2) {
	// the value of w, needs to be either 1 or 0
	if (t1.getW() + t2.getW() > 1) {
		return MyTuple(t1.getX() + t2.getX(), t1.getY() + t2.getY(), t1.getZ() + t2.getZ(), 1);
	}
	return MyTuple(t1.getX() + t2.getX(), t1.getY() + t2.getY(), t1.getZ() + t2.getZ(), t1.getW() + t2.getW());
}

bool MyTuple::equal(MyTuple t1, MyTuple t2) {
	if (std::fabs(t1.getX() - t2.getX()) < EPSILON && std::fabs(t1.getY() - t2.getY()) < EPSILON &&
		std::fabs(t1.getZ() - t2.getZ()) < EPSILON) {
		return true;
	}
	return false;
}

