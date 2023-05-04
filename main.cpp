#include <iostream>
#include "Tuple.h"
#include "Environment.h"
#include "Projectile.h"
using namespace std;

Projectile tick(Environment& env, Projectile& proj);

int main() {

	// initializing Projectile parameters
	Tuple position(0.0f, 1.0f, 0.0f, 1);
	Tuple velocity(1.0f, 1.0f, 0.0f, 0);
	Tuple norm_velo = velocity.normalize();
	// initializing Environment parameters
	Tuple gravity(0.0f, -0.5f, 0.0f, 0);
	Tuple wind(-0.5f, 0.0f, 0.0f, 0);

	Projectile proj1(position, norm_velo);
	Environment env1(gravity, wind);

	for (int i = 0; i < 100; i++) {
		cout << "after" << i << " ticks: " << tick(env1, proj1) << endl;
	}
	return 0;

}

Projectile tick(Environment& env, Projectile& proj) {
	proj.setPosition(proj.getPosition() + proj.getVelocity());
	proj.setVelocity(proj.getVelocity() + env.getGravity() + env.getWind());
	cout << "In the tick funciton" << proj << endl;
	return proj;
}
