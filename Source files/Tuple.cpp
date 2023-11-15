#include "Tuple.h"

Tuple operator-(const Tuple& t1, const Tuple& t2) {
	return Tuple(t1.getX() - t2.getX(), t1.getY() - t2.getY(), t1.getZ() - t2.getZ(), t1.getW() - t2.getW());
}

Tuple operator+(const Tuple& t1, const Tuple& t2) {
	return Tuple(t1.getX() + t2.getX(), t1.getY() + t2.getY(), t1.getZ() + t2.getZ(), t1.getW() + t2.getW());
}

std::ostream& operator<<(std::ostream& os, const Tuple& t) {
	os << "<" << t.getX() << ", " << t.getY() << ", " << t.getZ() << ", "
	   << t.getW() << ">";
	return os;
}

Tuple operator *(const Tuple& t, const float& num) {
	return Tuple(t.getX() * num, t.getY() * num, t.getZ() * num, t.getW());
}

Tuple operator /(const Tuple& t, const float& num) {
	return Tuple(t.getX() / num, t.getY() / num, t.getZ() / num, t.getW());
}

bool Tuple::equal(Tuple t2) {
	if (std::fabs(this->getX() - t2.getX()) < EPSILON && std::fabs(this->getY() - t2.getY()) < EPSILON &&
		std::fabs(this->getZ() - t2.getZ()) < EPSILON) {
		return true;
	}
	return false;
}

