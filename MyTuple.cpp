#include "MyTuple.h"

MyTuple operator-(const MyTuple& t1, const MyTuple& t2) {
	return MyTuple(t1.getX() - t2.getX(), t1.getY() - t2.getY(), t1.getZ() - t2.getZ(), t1.getW() - t2.getW());
}

MyTuple operator+(const MyTuple& t1, const MyTuple& t2) {
	return MyTuple(t1.getX() + t2.getX(), t1.getY() + t2.getY(), t1.getZ() + t2.getZ(), t1.getW() + t2.getW());
}

std::ostream& operator<<(std::ostream& os, const MyTuple& t) {
	os << "<" << t.getX() << ", " << t.getY() << ", " << t.getZ() << ", "
	   << t.getW() << ">";
	return os;
}

MyTuple operator *(const MyTuple& t, const float& num) {
	return MyTuple(t.getX() * num, t.getY() * num, t.getZ() * num, t.getW());
}

MyTuple operator /(const MyTuple& t, const float& num) {
	return MyTuple(t.getX() / num, t.getY() / num, t.getZ() / num, t.getW());
}

bool MyTuple::equal(MyTuple t2) {
	if (std::fabs(this->getX() - t2.getX()) < EPSILON && std::fabs(this->getY() - t2.getY()) < EPSILON &&
		std::fabs(this->getZ() - t2.getZ()) < EPSILON) {
		return true;
	}
	return false;
}

