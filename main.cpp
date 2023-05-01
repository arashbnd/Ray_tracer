#include <iostream>
#include "MyTuple.h"
using namespace std;

int main() {
	MyTuple tobj(1, 2, 3, 1);
	MyTuple tobj2(2, 3, 4, 1);
	cout << tobj << " X " << tobj2 << " = " << tobj.crossProduct(tobj2) << endl;
	cout << tobj2 << " X " << tobj << " = " << tobj2.crossProduct(tobj) << endl;

	return 0;
}