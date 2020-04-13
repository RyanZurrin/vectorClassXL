#include "Vector3D.h"
using namespace std;
Vector3D::Vector3D() //constructor
{
  x=0;
  y=0;
  z=0;
}
Vector3D::Vector3D(ld x1,ld y1,ld z1)  //initializing object with values.
{
  x=x1;
  y=y1;
  z=z1;
  magnitude = returnMagnitude();
}
Vector3D::Vector3D(const Vector3D &vec)
{
  x=vec.x;
  y=vec.y;
  z=vec.z;
  magnitude = returnMagnitude(); 
}

void Vector3D::showAllData()
{
    magnitude = returnMagnitude();
    cout<< setprecision(2) << fixed;
  	cout<< "x: " << x << " ";
    cout<< "y: " << y << " ";
    cout<< "z: " << z << endl;
    cout<< "mag: " << magnitude << endl;			  
}

//addition

Vector3D Vector3D::operator+(const Vector3D &vec)
{
    return Vector3D(x+vec.x,y+vec.y,z+vec.z);
}
Vector3D Vector3D::operator+(const Vector &vec)
{
    return Vector3D(x+vec.x,y+vec.y,z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
    return *this;
}
//substraction//
Vector3D Vector3D::operator-(const Vector3D &vec)
{
    return Vector3D(x-vec.x,y-vec.y,z-vec.z);
}

Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
    x-=vec.x;
    y-=vec.y;
    z-=vec.z;
    return *this;
}

//scalar multiplication

Vector3D Vector3D::operator*(ld value)
{
    return Vector3D(x*value,y*value,z*value);
}



Vector3D &Vector3D::operator*=(ld value)
{
    x*=value;
    y*=value;
    z*=value;
    return *this;
}

//scalar division
Vector3D Vector3D::operator/(ld value)
{
    assert(value!=0);
    return Vector3D(x/value,y/value,z/value);
}

Vector3D &Vector3D::operator/=(ld value)
{
    assert(value!=0);
    x/=value;
    y/=value;
    z/=value;
    return *this;
}


Vector3D &Vector3D::operator=(const Vector3D &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
    return *this;
}

//Dot product
ld Vector3D::dot_product(const Vector3D &vec)
{
    return x*vec.x+vec.y*y+vec.z*z;
}

//cross product
Vector3D Vector3D::cross_product(const Vector3D &vec)
{
    ld ni=y*vec.z-z*vec.y;
    ld nj=z*vec.x-x*vec.z;
    ld nk=x*vec.y-y*vec.x;
    return Vector3D(ni,nj,nk);
}

ld Vector3D::returnMagnitude()
{
    return sqrt(square());
}

ld Vector3D::square()
{
    return x*x+y*y+z*z;
}

Vector3D Vector3D::normalization()
{
    assert(returnMagnitude()!=0);
    *this/=returnMagnitude();
    return *this;
}

ld Vector3D::distance(const Vector3D &vec)
{
    Vector3D dist=*this-vec;
    return dist.returnMagnitude();
}

ld Vector3D::returnX()
{
    return x;
}

ld Vector3D::returnY()
{
    return y;
}

ld Vector3D::returnZ()
{
    return z;
}

void Vector3D::disp()
{
    cout<<x<<" "<<y<<" "<<z<<endl;
}


