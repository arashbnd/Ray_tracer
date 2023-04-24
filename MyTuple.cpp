#include "MyTuple.h"

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

bool MyTuple::equal(MyTuple t2) {
	if (std::fabs(this->getX() - t2.getX()) < EPSILON && std::fabs(this->getY() - t2.getY()) < EPSILON &&
		std::fabs(this->getZ() - t2.getZ()) < EPSILON) {
		return true;
	}
	return false;
}

