#include "vect.h"
#include "vect3D.h"
#include <stdio.h> 
#include <assert.h> 
Vector3D::Vector3D(const Vector3D &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
}


void Vector::showAllData()const
{
	cout << "x: " << Vector3D::returnX << " ";
    cout << "y: " << Vector3D::returnY << " ";
    cout << "z: " << Vector3D::returnZ << endl;
    cout << "mag: " << Vector3D::returnMagnitude << endl;

}

//addition

Vector3D Vector3D::operator+(const Vector3D &vec)
{
    return Vector3D(x+vec.x,y+vec.y,z+vec.z);
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

int main()
{

    
}
