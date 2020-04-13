/*______________________________________________________________________________
author:			Ryan Zurrin
program:		testVect.cpp
due date: 			
assignment:	build and test a Vector class for doing math on vectors	
purpose:    gain a deeper understanding of classes and operator overloading
______________________________________________________________________________*/
#include "vect.h"
#include "Vector3D.h"

using namespace std;
//______________________________________________________________________________
//

int main()																																
{	
	ld x = 15;	
	ld y = 127;//(PI)/4*DEGREE;
	
	cout << x << endl;
	cout << y << endl;
	
	Vector v(x, y, 'p');
	v.showAllData();
	v.showRectCord();
	v.showAllData();
	Vector v2 = -v;
	cout << "inverse vector: " << endl;
	v2.showAllData();	
	
	Vector v3(2,3);
	//v3.showAllData();
	
	Vector3D a=Vector3D(21,5,7);
	a.showAllData();	
  Vector3D b=Vector3D(3,7,10);
  b.showAllData();
	Vector3D c=a+v;
	cout << " here " << endl;
	c.showAllData();	
	c.setMode('p');
	c = c * PI/4;
	c.showAllData();
    //provide any operation.
	//v3.setPolarCurve();
	//v3.showPolarCurve();
	
	return 0;
}
/*______________________________________________________________________________
	  All my unit tests for this class and module are below this line
	______________________________________________________________________________
	
		Vector v1(1000, 180, 'p');
	v1.showAllData();
	Vector v2(3,4);
	v2.showAllData();
	//cout << "v2: " << v2 <<endl;
	Vector v3 = (2*v1 + 5);
	cout << "v2: " << v2;
	cout << "v3: " << v3 << endl;
	v3.showAllData();
	Vector v4 = v1 + 8;
	cout << "v4: " << v4 << endl;
	v4.showAllData();
	***test 1***

	cout << "test1:\n";
	Vector test1;
	test1.setCoordinates(3,4);
	test1.displayAllData();
	---------------------------------------------

	***test 2***

	cout << "test2:\n";
	Vector test2;
	test2.setCoordinates(5, 53.13, 'p');
	test2.displayAllData();
	---------------------------------------------

	***test 3***

	cout << "test0:\n";
	Vector testO;
	testO.setCoordinates(15, 13);
	testO.displayAllData();
	---------------------------------------------

	***test 4***

	cout << "\ntest Object 1 with default constructor:\n";
	Vector testObject;
	testObject.displayAllData();
	++testObject;
	testObject++;
	cout << "after testOject++:\n";
	testObject.displayAllData();
	cout << "\nusing setPolarCord to change x, y:\n";
	testObject.setPolarCord(7.07, 135);
	testObject.displayAllData();
	---------------------------------------------

	***test 5***

	cout << "test object2\n";
	Vector testObject2(3,4);
	testObject2.returnAngle();
	testObject2.returnMagnitude();
	testObject2.returnX();
	testObject2.returnY();
	testObject2.displayAllData();
	---------------------------------------------

	***test 6*** dependent on testObject and testObject2
	include unit test 4 and unit test 5 before test 6 code

	cout << "test object3:\n";
	Vector testObj3 = testObject2 + testObject;
	testObj3.displayAllData();
	---------------------------------------------

	***test 7***

	cout << "test4:\n";
	Vector testObj4(-1.99925, 8.99924);
	testObj4.displayAllData();
	---------------------------------------------

	***test 8***	

	cout << "\ntest object 2 with constructor set to polar mode\n"
			 << "using mag 5, angle 53.13 degrees:\n";
	Vector testObj2(5, 53.13, 'p');	
	testObj2.displayAllData();
	testObj2.displayRectCord();
	---------------------------------------------

	***test 9***

	cout << "test object 3 with constructor using mode in default rect\n"
			 << "using x = 3, y = 4\n";
	Vector testObj3(3, 4);
	testObj3.displayAllData();
	---------------------------------------------
	
	***test 10***
	
	cout << "test1:\n";
	Vector test1;
	test1.setCoordinates(3,4);
	cout << test1;
	test1.returnX();
	test1.setMode('p');
	test1.returnMode();
//test1.returnAngle();
	test1.setX(9);
//test1.returnMagnitude();
//test1.showAllData();
	test1.setY(23);
//test1.returnAngle();
//test1.returnMagnitude();
	test1.setMag(5);
//test1.showAllData();
	test1.setAngle(90);
/test1.showAllData();
	test1.showVector();
	test1.setMode('r');
	test1.showVector();
	--------------------------------------------------
	
	***test 11***
	
		//cout << "test1:\n";
	Vector test1;
	test1.setCoordinates(145,45, 'p');
	//cout << test1;
	test1.showPolarCord();
	test1.returnX();
	//test1.setMode('p');
	test1.returnMode();
	//test1.returnAngle();
	test1.setX(9);
	test1.showAllData();
	test1++;
	test1.showRectCord();
	-test1;
	test1.showAllData();
	test1.returnMagnitude();
//	test1.showAllData();
//	test1.setY(23);
//	test1.returnAngle();
//	test1.returnMagnitude();
//	test1.setMag(5);
	//test1.showAllData();
	//test1.setAngle(90);
	//test1.showAllData();
	test1.showVector();
//	test1.setMode('r');
//	test1.showVector();
	Vector test2(9, 270, 'p');
	test2.showAllData();
	//test2.setMode('p');
	//test2.returnMode();
	//Vector test3 = test2 + test1;
	//test3.showAllData();
		--------------------------------------------------
	
	***test 12***
	
	int main()
{
	cout << "\nv1:\n";
	Vector v1(3, -1);
	v1.showAllData();
	cout << "\nv2: \n";
	Vector v2(2, 3);
	v2.showAllData();
	cout << "\nv3:\n(equals v1 + v2)\n";
	Vector v3 = v1 + v2;
	v3.showAllData();
	cout << "\nv4:\n(equals v1 - v2)n";
	Vector v4 = v1 - v2;
	v4.showAllData();
	cout << "\nv5:\n(equals v1 + v2 + v3)\n";
	Vector v5 = v1 + v2 + v3;
	v5.showAllData();
	cout << "\nv6: \n(equals v1 - v2 - v3)\n";
	Vector v6 = v1 - v2 - v3;
	v6.showAllData();
	Vector v7 = v1 * v2;
	cout << "\nv7:\n(equals v1* v2)\n";
	v7.showAllData();
	cout << "\nv7:\n(equals v7 * 5(scaler)))\n";
	v7 = v7 *5;
	v7.showAllData();
	cout << "\nv8:\n(equals -v7)\n";
	Vector v8 = -v7;
	v8.showAllData();	
	cout << "\nv9:\n(equals v7 + v8)\n";
	Vector v9 = v8 + v7;
	v9.showAllData();
	cout << "\nv11:\n(equals v7 - v8)\n";
	Vector v11 = v7 - v8;
	v11.showAllData();
	if (v1 > v2){
		cout << "\nv1 is bigger than v2\n";
	}
	else{
		cout << "\nv2 is bigger\n";
	}
	v2.returnAngle();
	Vector v10(-5, 45);
	v10.showAllData();
	v10.setMag(-6.8);
	v10.returnMagnitude();
	//v10.showAllData();
	v10.setAngle(155);
	//v10.showAllData();
	v10.showVector();
	return 0;
		--------------------------------------------------
	
	***test 13***
	
		Vector v1(3, 12, 'r');
	cout << v1 << endl;
	v1.showAllData();
	cout << --v1 << endl;
	v1.showAllData();
	cout << v1-- << endl;
	cout << v1-- << v1-- << v1-- << v1++;
	v1.showAllData();
	cout << "\nset cordinates\n";
	cin >> v1;
	v1.showAllData();

		--------------------------------------------------
	
	***test 14***
	
		Vector v1(1,2);
	v1.showAllData();
 	v1 = v1 * 2;
 	//v1.setMode('p');
 	//v1.showAllData();
 	cout << v1 << endl;
 	cout << "\ntest2\n";
 	Vector v2(2,3);
	v2.showAllData();
  Vector v3 = v1 * v2;
  double test = v3.returnY('l');
  cout << "test: "<< test << endl;
  v3.returnMagnitude();
  v3.returnAngle();
 	v3.showAllData();
 	Vector v4 = 3 * v3;
 	v4.returnX();
 	//cout << v4* v2;; 
 // v2.showAllData();
 //	v1.showAllData();
		--------------------------------------------------
	
	***test 15***
	
	double a;
	Vector v1(8, 23.5, 'p');
	cout << v1;
	a = v1.returnAngle();
	v1.returnMode('p');
	v1.setMode('r');
	cout << v1;
		--------------------------------------------------
	
	***test 16***
	
	Vector v(3, 4);
	cout << v << endl;
	v.setMode('p');
	cout << v << endl;
	cout << 133 * v << endl;
	v.setMode('r');
	
	cout << v * 133 << endl;
	
	cout << "\nNew test with minus:" << endl;
	Vector v1(1,2);
	cout << "v: "<< v << endl << "v1: "<< v1 << endl;
	cout << "v - v1: " << v - v1 << endl;
	cout << " v1 - v: " << v1 - v << endl;
	//v.setMode('p');
	v1.setMode('P');
	cout << "v: " << v << endl << "v1: " << v1 << endl;
	Vector v3 = v - v1;
	cout << "\nmode v3: " << v3.returnMode() << endl;
	cout << "\nv3: " << v3 << endl;
	Vector v4 = v1 - v;
	cout << "\nmode v4: " << v4.returnMode() << endl;
	cout << "\nv4: " << v4 << endl;
	v4.setMode('p');
	cout << v4 << endl;
	v4.showAllData();
		--------------------------------------------------
	
	***test 17***
	
	Vector v(3, 4);
	v.showPolarCord();
	cout << v << endl;
	
	cout << v * 3 << endl;
	
	cout << v - 8 << endl;
	

	cout << "\nv:" << v << endl;
	v.showRectCord();
	cout << v + 8 << endl;
	Vector v2=  v + 8;
	cout << v2 << endl;
	v.setMode('p');
	cout << 2.56 - v << endl;
	v.setMode('r');
	cout << 2.56 - v << endl;
	Vector v3 = v2 + 2.56 - v;
	v3.showAllData();
	cout << "crazy: "<<  v2 + 2.56 - v * 21 - v3 + 3.7 * v;
	cout << "crazy2: "<<  v2 + 2.56 - v * 21 - v3 + 3.7 * v +2;
	cout << "crazy3: "<<  -(v2 + 2.56 - v * 21 - v3 + 3.7 * v +2);
	cout << "crazy4: "<< v2 * v2 + 2.56 - v * 21 - v3 + 3.7 * v +2 * v;
	cout << "crazy5: "<< v2 * v2 + 2.56 - v * 21 - v3 + 3.7 * v +2 * v + 5;
	
	Vector v4 = v2 + 2.56 - v * 21 - v3;
	v4.showAllData();
		--------------------------------------------------
	
	***test 18***
	
	*/
