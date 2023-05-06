#include "Color.h"

Color operator *(const Color& c1, const Color& c2) {
	return Color(c1.getX() * c2.getX(), c1.getY() * c2.getY(), c1.getZ() * c2.getZ());
}