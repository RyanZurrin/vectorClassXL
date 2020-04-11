//author:			Ryan Zurrin
//file:           vect.h (XL)

// Specification file for a  vect class 

#ifndef VECT_H
#define VECT_H
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <complex>
#include "vect3D.h"

using namespace std;
typedef long double ld;

const ld PI		 = 3.1415926535898;
const ld DEGREE = 180/PI;
const ld RADIAN = PI/180; 


struct PolarCurve
{   
   ld theta = 1.0,
      r = 0,
      x = r*cos(theta),
      y = r*sin(theta);  
};

struct DirectionalVector
{
 ld dvx, dvy, dvz; 
};

class Vector
{
   private:
      ld x, y, magnitude, angle,
                  arcLength, revolutionAngle_inDegrees;
      char mode;
      PolarCurve Curve;
      DirectionalVector ParametricEQ;
      DirectionalVector calculate_parallel_vector(),
                        calculate_parametric_equation();
      void 	  validate_setMode(),
              validate_magnitude(),
              adjust_angle(),
              calculate_rectangular(),
              calculate_polar(),
              calculate_arcLength(),
              calculate_derivitive();
      

   public:			
      Vector(char _mode='r');     
      Vector(ld, ld, char _mode = 'r');   
			   
      void showAllData()const;
      void showVector()const;    
      void showRectCord()const;
      void showPolarCord()const;
      void showRevolutionAngle()const;
      void showPolarCurve()const;
      void showParametricEquation()const;
      
      ld returnX(char v = 'r')const;
      ld returnY(char v = 'r')const;
      ld returnMag(char v = 'r')const;
      ld returnAngle(char v = 'r')const;
      ld returnArcLength(char v = 'r')const;

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
      void set2dParametricPoints();
      void set3dParametricPoints();
      
      bool operator>(const Vector &)const;
      bool operator<(const Vector &)const;
      bool operator==(const Vector &)const;
      
      Vector operator+(const Vector &)const;
      Vector operator+(const ld number)const;
      Vector operator+()const;        
      Vector operator++();
      Vector operator++(int);

      Vector operator-(const Vector &);
      Vector operator-(const ld number)const;
      Vector operator-()const;      
      Vector operator--();
      Vector operator--(int);
      
      Vector operator*(const ld)const;
      
      friend Vector operator*(ld s, Vector& v);
      friend Vector operator*(Vector& v, Vector& s);
      friend Vector operator-(ld s, Vector& v);
      friend Vector operator+(ld s, Vector& v);      
      friend ostream& operator<<(ostream&, const Vector&);
      friend istream& operator>>(istream&, Vector&);  
      
      ~Vector();    
};
#endif
