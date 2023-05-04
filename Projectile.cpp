#include "Projectile.h"

std::ostream& operator<<(std::ostream& os, const Projectile& p) {
	os << "Position: " << p.getPosition() << " Velocity: " << p.getVelocity() << std::endl;
	return os;
}
