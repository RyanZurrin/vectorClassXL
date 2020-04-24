//author:			Ryan Zurrin
//file:           vect.h (XL)

// Specification file for a  vect class 
///
#ifndef VECT_H
#define VECT_H
#include <iostream>
#include <iomanip>
#include <cctype>
#include <assert.h>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <complex>
#include <vector>
#include <Eigen/dense>
#include "exceptionHandler.h"

using namespace std;
typedef long double ld;

const ld PI		 = 3.1415926535898;
const ld DEGREE = 180/PI;
const ld RADIAN = PI/180; 



struct PolarCurve
{   
   ld theta = 1.0;
   ld  r = 0;
   ld  x = r*cos(theta);
   ld  y = r*sin(theta);  
};

class Vector 
{
	static int object_counter;
	 	 
   friend class Vector3D;  
			  
   protected:
      ld x, y, magnitude, angle,
         arcLength, revolutionAngle_inDegrees;
      char mode;  //sets mode to Polar w/ 'p' or Rectangular w/ 'r'           
      
      //void    calculate_parametric_equation();
      void 	  validate_setMode();
      void    validate_magnitude();
      void    adjust_angle();
      void    calculate_rectangular();
      void    calculate_polar();
      void    calculate_arcLength();
      //void    calculate_derivitive();

   private:
      PolarCurve Curve; //structure for storing data on a polar curve
      Vector calculate_parallel_vector2d(const Vector, const Vector);

   public:			
		Vector(); //default constructor
      Vector(char);//mode select, defaults to 0, in rectangular, constructor
      Vector(ld, ld, char _mode = 'r'); //constructor takes both coordinates and mode
      Vector(const Vector &);	//copy constructor		   
      virtual void showAllData()const; //virtual so any derived classes must redefine
      virtual void showVector()const;    
      virtual void showRectCord()const;
      void showPolarCord()const;
      virtual void showRevolutionAngle()const;
      virtual void showPolarCurve()const;
      //virtual void showParametricEquation()const;
      
      ld returnX(char v = 'r')const;
      ld returnY(char v = 'r')const;      
      ld returnMag(char v = 'r')const;
      ld returnAngle(char v = 'r')const;
      ld returnArcLength(char v = 'r')const;
      int returnObjectCount(){return object_counter;}
			
      char returnMode(char v = 'r')const;
      
      void setCoordinates(ld, ld, char _mode = 'r');
      void setRectCord(ld, ld);
      void setPolarCord(ld, ld);     
      void setX(ld);
      void setY(ld);
      void setMag(ld);
      void setAngle(ld);
      void setMode(char); 
      void setPolarCurve();
      
      //virtual void setParametricPoints();      
      
      bool operator>(const Vector &)const;
      bool operator<(const Vector &)const;
      bool operator==(const Vector &)const;
      
      
      virtual Vector operator+(const Vector &)const;
      Vector operator+(const ld number)const;      
      Vector &operator+=(const Vector &);

      Vector operator+()const;        
      Vector operator++();
      Vector operator++(int);

      Vector operator-(const Vector &);
      Vector operator-(const ld number)const;
      Vector operator-()const;      
      Vector operator--();
      Vector operator--(int);

      //virtual Vector operator/(ld value);
      Vector operator/(ld);
      Vector operator/=(ld);
      Vector &operator=(const Vector &);
      Vector &operator=(const Vector *);
      
      virtual Vector operator*(const ld)const;
      
      friend Vector operator*(ld s, Vector& v);
      friend Vector operator*(Vector& v, Vector& s);
      friend Vector operator-(ld s, Vector& v);
      friend Vector operator+(ld s, Vector& v);      
      friend ostream& operator<<(ostream&, const Vector&);
      //friend Vector& operator<<(Vector&, const Vector&);
      friend istream& operator>>(istream&, Vector&);  
      
      virtual ~Vector();    
};
#endif
