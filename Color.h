#include "Tuple.h"
#pragma once

class Color: public Tuple {
public:
	Color(float r, float g, float b) : Tuple(r, g, b, 0) {}

	

	friend Color operator *(const Color& c1, const Color& c2);
};

