#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "vect.h"
#include <stdio.h> 
#include <assert.h> 
#include <iostream>
using namespace std;
typedef long double ld;
class Vector3D : public Vector
{
friend class Vector;
protected:
    ld z;
public:    
    Vector3D(); //constructor    
    Vector3D(ld, ld, ld);  //initializing object with values.    
    Vector3D(const Vector3D &vec);    //copy constructor
    Vector3D operator+(const Vector3D &vec);    //addition
    Vector3D operator+(const Vector &vec);
    Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
    Vector3D operator-(const Vector3D &vec);    //substraction
    Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
    Vector3D operator*(ld value);    //multiplication
    Vector3D &operator*=(ld value);  //assigning new result to the vector.
    Vector3D operator/(ld value);    //division
    Vector3D &operator/=(ld value);  //assigning new result to the vector
    Vector3D &operator=(const Vector3D &vec);
    ld dot_product(const Vector3D &vec); //scalar dot_product
    Vector3D cross_product(const Vector3D &vec);    //cross_product
    ld returnMagnitude();  //magnitude old the vector
    Vector3D normalization();   //nor,malized vector
    ld square(); //gives square old the vector
    ld distance(const Vector3D &vec);    //gives distance between two vectors
    ld returnX(); //return x
    ld returnY(); //return y
    ld returnZ(); //return z
    void showAllData();
    void disp();    //display value old vectors
    //friend ostream& operator<<(ostream&, const Vector3D&);
};
#endif
