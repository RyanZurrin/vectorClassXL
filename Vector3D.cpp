#include "Vector3D.h"
using namespace std;
Vector3D::Vector3D() //constructor
{
  x=0;
  y=0;
  z=0;
  object_counter++;
	cout<< object_counter << ": " <<"in the 3dVector default constructor"<<endl;
}
Vector3D::Vector3D(ld x1,ld y1,ld z1)  //initializing object with values.
{
  x=x1;
  y=y1;
  z=z1;
  magnitude = returnMagnitude();
  set_allAngles();  
  object_counter++;
	cout<< object_counter << ": " <<"in the x,y,z constructor" << endl;;
}
Vector3D::Vector3D(const Vector3D &vec)
{
  x=vec.x;
  y=vec.y;
  z=vec.z;
  magnitude = returnMagnitude();
  set_allAngles();
  object_counter++;
	cout<< object_counter << ": " <<"in the 3dcopy constructor";
}
void Vector3D::showAllData()
{
    magnitude = returnMagnitude();
    cout<< setprecision(2) << fixed;
  	cout<< "x: " << x << " ";
    cout<< "y: " << y << " ";
    cout<< "z: " << z << endl;
    cout<< "mag: " << magnitude << endl;
    cout << "angles aX: "<< xAngle << ", aY: "<<yAngle<<", aZ: "<<zAngle
         << endl;		
		returnMode('p');	  
}
void Vector3D::showPolarCord()const
{
	cout << "polar<" << x << ", " << y << ", " << z << ">" << endl;
}
void Vector3D::set_allAngles()
{
    xAngle = return_xAngle();
    yAngle = return_yAngle();
    zAngle = return_zAngle();
    //angle = 
}

//addition
Vector3D Vector3D::operator+(const Vector3D &vec)const
{
	cout << "in Vector3D::operator+(const Vector3D &vec)"<<endl;
    return Vector3D(x+vec.x,y+vec.y,z+vec.z);
}
Vector3D Vector3D::operator+(Vector &vec)const
{
	cout << "in Vector3D::operator+(Vector &vec)const "<<endl;
    return Vector3D(x+vec.x,y+vec.y,z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
	cout << "in &Vector3D::operator+=(const Vector3D &vec)"<<endl;
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
    set_allAngles();
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
    set_allAngles();
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
    set_allAngles();
    return *this;
}

//scalar division
Vector3D Vector3D::operator/(ld value)
{
      
    again:
    if (value != 0)
        return Vector3D(x / value, y / value, z / value);
    else
    {
        do
        {
            cout << "**ERROR** can't divide by 0, enter new number\n>";
            cin >> value;
            cin.clear();
            cin.ignore(100, '\n');
        } while (!cin || value == 0);
        goto again;
    }
}
Vector3D &Vector3D::operator/=(ld value)
{
    assert(value!=0);
    x/=value;
    y/=value;
    z/=value;
    set_allAngles();
    return *this;
}
Vector3D &Vector3D::operator=(const Vector3D &vec)
{
    x=vec.x;
    y=vec.y;
    z=vec.z;
    return *this;
}
ostream& operator<<(ostream& os, const Vector3D & v)
{	
  if(v.mode == 'R' || v.mode == 'r'){
  	v.showRectCord(); 
  }
  else{
  	v.showPolarCord();
  }  
  return os;
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
ld Vector3D::return_xAngle()
{
    return atan2(sqrt(y * y + z * z), x) * DEGREE;
}
ld Vector3D::return_yAngle()
{
    return atan2(sqrt(x * x + z * z), y) * DEGREE;
}
ld Vector3D::return_zAngle()
{
    return atan2(sqrt(x * x  + y * y), z) * DEGREE;
}
void Vector3D::disp()
{
    cout<<x<<" "<<y<<" "<<z<<endl;
}

Vector3D::~Vector3D()
{	
	--object_counter;
	cout << "In Vector3D destructor: "<< object_counter << " objects remain\n"
			 << endl;
}


