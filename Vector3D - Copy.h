#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "vect.h"


using namespace std;
typedef long double ld;
class Vector3D : public Vector
{
friend class Vector;
private:
    ld z, xAngle, yAngle, zAngle;
    void set_allAngles();  

public:    
    Vector3D(); //constructor    
    Vector3D(ld, ld, ld);  //initializing object with values.    
    Vector3D(const Vector3D &vec);    //copy constructor    
    
    void setX();
    void setY();
    void setZ();
		void set_xAngle();
		void set_yAngle();
		void set_zAngle();
		
	  void showAllData();
	  void showPolarCord()const;
	  void disp();    //display value old vectors
    ld returnX(); //return x
    ld returnY(); //return y
    ld returnZ(); //return z
    ld return_xAngle(); //return x angle
    ld return_yAngle(); //return y angle
    ld return_zAngle(); //return z angle
    
    ld square(); //gives square old the vector
    ld returnMagnitude();  //magnitude old the vector
    ld dot_product(const Vector3D &vec); //scalar dot_product
    ld distance(const Vector3D &vec);    //gives distance between two vectors
    Vector3D cross_product(const Vector3D &vec);    //cross_product
    Vector3D normalization();   //nor,malized vector    
    
    Vector3D operator+(const Vector3D &vec)const;    //addition
    Vector3D operator+(Vector &vec)const;
    Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
    Vector3D operator-(const Vector3D &vec);    //substraction
    Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
    Vector3D operator*(ld value);    //multiplication
    Vector3D &operator*=(ld value);  //assigning new result to the vector.
    Vector3D operator/(ld value);    //division
    Vector3D &operator/=(ld value);  //assigning new result to the vector
    Vector3D &operator=(const Vector3D &vec);
    friend Vector3D &operator<<(Vector3D &, const Vector3D &);    
    friend ostream& operator<<(ostream&, const Vector3D&);
    ~Vector3D(); 
};
#endif
