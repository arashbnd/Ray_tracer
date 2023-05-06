#include <iostream>
#include "Tuple.h"
#include "Environment.h"
#include "Projectile.h"
#include "Color.h"

using namespace std;

Projectile tick(Environment& env, Projectile& proj);

int main() {
	Color c1(1.0f, 0.2f, 0.4f) , c2(0.9f, 1.0f, 0.1f);
	Color c3 = c1 * c2;
	cout << c1 << " * " << c2 << " = " << c3;
	return 0;

}

Projectile tick(Environment& env, Projectile& proj) {
	proj.setPosition(proj.getPosition() + proj.getVelocity());
	proj.setVelocity(proj.getVelocity() + env.getGravity() + env.getWind());
	cout << "In the tick funciton" << proj << endl;
	return proj;
}
