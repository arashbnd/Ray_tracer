#include <iostream>
#include "MyTuple.cpp"

using namespace std;

int main() {
	MyTuple tobj(1, 2, 3, 1);
	MyTuple tobj2(1, 2, 3, 1);
	cout << "object x = " << tobj.getX() << endl;
	cout << "object y = " << tobj.getY() << endl;
	cout << "object z = " << tobj.getZ() << endl;
	cout << "object w = " << tobj.getW() << endl;
	cout << "object is(point or vector):" << tobj.tupleType() << endl;
	cout << "\n";
	MyTuple sub_result = tobj - tobj2;
	cout << "sub_result x = " << sub_result.getX() << endl;
	cout << "sub_result y = " << sub_result.getY() << endl;
	cout << "sub_result z = " << sub_result.getZ() << endl;
	cout << "sub_result w = " << sub_result.getW() << endl;
	cout << "\n";
	MyTuple add_result = tobj + tobj2;
	cout << "add_result x = " << add_result.getX() << endl;
	cout << "add_result y = " << add_result.getY() << endl;
	cout << "add_result z = " << add_result.getZ() << endl;
	cout << "add_result w = " << add_result.getW() << endl;
	
	cout << "is t1 == t2: " << equal(tobj, tobj2) << endl;
	return 0;
}