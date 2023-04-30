#include <iostream>
#include "MyTuple.h"
using namespace std;

int main() {
	MyTuple tobj(3, 2, 1, 1);
	MyTuple tobj2(5, 6, 7, 1);
	
	cout << "Normalization of " << tobj << " is: " << tobj.normalize();
	return 0;
}