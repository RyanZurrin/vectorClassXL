#ifndef VECT3D_H
#define VECT3D_H
#include "vect.h"
#include <stdio.h> 
#include <assert.h> 
typedef long double ld;
class Vector3D : public Vector
{
//friend class Vector;
public:
    ld x,y,z;
    Vector3D() //constructor
    {
        x=0;
        y=0;
        z=0;
    }

    Vector3D(ld x1,ld y1,ld z1=0)  //initializing object with values.
    {
        x=x1;
        y=y1;
        z=z1;
    }
    Vector3D(const Vector3D &vec);    //copy constructor
    Vector3D operator+(const Vector3D &vec);    //addition
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
    void disp();    //display value old vectors
};
#endif
