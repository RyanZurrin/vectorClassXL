//author:			Ryan Zurrin
//file:           vect.h (XL)

// Specification file for a  vect class 
///
#ifndef VECT_H
#define VECT_H
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <complex>
#include <eigen3/Eigen/Core>

using namespace std;
typedef long double ld;

const ld PI		 = 3.1415926535898;
const ld DEGREE = 180/PI;
const ld RADIAN = PI/180; 



class Vector 
{
   static int object_counter;	 	 
   friend class Vector3D; 			  
   protected:
      ld x, y, magnitude, angle,
         arcLength, revolutionAngle_inDegrees;
      char mode_;  //sets mode to Polar w/ 'p' or Rectangular w/ 'r'           
      
      //void    calculate_parametric_equation();
      void 	  validate_setMode();
      void    normalize_magnitude();
      void    calculate_magnitude();
      void    calculate_angle();
      void    adjust_angle();
      void    calculate_rectangular();
      void    calculate_polar();
      void    calculate_arcLength();
      
      //void    calculate_derivative();

  // private:
  //    Vector calculate_parallel_vector2d( Vector&, Vector&);

   public:			
		Vector(); //default constructor
      Vector(char);//mode select, defaults to 0, in rectangular, constructor
      Vector(ld, ld, char _mode = 'r'); //constructor takes both coordinates and mode
      Vector(const Vector &);	//copy constructor		   
      virtual void showAllData()const; //virtual so any derived classes must redefine
      virtual void showVector()const;    
      virtual void showRectCord()const;
      virtual void showPolarCord()const;
      virtual void showRevolutionAngle()const;
      
      //virtual void showPolarCurve()const;
      //virtual void showParametricEquation()const;
      void show_x()const;
      void show_y()const;
      void show_mag()const;
      void show_angle()const;
      void show_mode()const;
      void show_arcLength()const;
	
      ld return_x(char v = 'r')const;
      ld return_y(char v = 'r')const;
      ld return_mag(char v = 'r')const;
      ld return_angle(char v = 'r')const;
      ld return_arcLength(char v = 'r')const;
      static int return_objectCount(){return object_counter;}
			
      char return_mode(char v = 'r')const;
      
      void set_coordinates(ld, ld, char _mode = 'r');
      void set_rectCord(ld, ld);
      void set_polarCord(ld, ld);     
      void set_x(ld);
      void set_y(ld);
      void set_mag(ld);
      void set_angle(ld);
      void set_mode(char); 
      //void setPolarCurve();
      
      //virtual void setParametricPoints();      
      
      bool operator>(const Vector &)const;
      bool operator<(const Vector &)const;
      bool operator==(const Vector &)const;
      
      
      virtual Vector operator+(const Vector &)const;
      Vector operator+(ld number)const;      
      Vector &operator+=(const Vector &);

      Vector operator+()const;        
      Vector operator++();
      Vector operator++(int);

      Vector operator-(const Vector &);
      Vector operator-(ld number)const;
      Vector operator-()const;      
      Vector operator--();
      Vector operator--(int);

      //virtual Vector operator/(ld value);
      virtual Vector operator/(ld);
      virtual Vector operator/=(ld);
      Vector &operator=(const Vector &);
      Vector &operator=(const Vector *);
      Vector &operator=(Vector&& right)noexcept;
      Vector(Vector&& temp)noexcept;
	  
      
      virtual Vector operator*(ld)const;
      
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
