#include <iostream>
#include "MyTuple.h"
#include "Environment.h"
#include "Projectile.h"
using namespace std;

Projectile tick(Environment env, Projectile proj);

int main() {
	MyTuple tobj(1, 2, 3, 1);
	MyTuple tobj2(2, 3, 4, 1);
	cout << tobj << " X " << tobj2 << " = " << tobj.crossProduct(tobj2) << endl;
	cout << tobj2 << " X " << tobj << " = " << tobj2.crossProduct(tobj) << endl;
	// initializing Projectile parameters
	MyTuple position(0.0f, 1.0f, 0.0f, 1);
	MyTuple velocity(1.0f, 1.0f, 0.0f, 0);
	MyTuple norm_velo = velocity.normalize();
	// initializing Environment parameters
	MyTuple gravity(0.0f, -0.01f, 0.0f, 0);
	MyTuple wind(-0.01f, 0.0f, 0.0f, 0);

	Projectile proj1(position, norm_velo);
	Environment env1(gravity, wind);

	for (int i = 0; i < 6; i++) {
		cout << "tick after" << i << " iterations: " << tick(env1, proj1) << endl;
	}
	return 0;

}

Projectile tick(Environment env, Projectile proj) {
	return Projectile(proj.getPosition() + proj.getVelocity(),
		proj.getVelocity() + env.getGravity() + env.getWind());
}
