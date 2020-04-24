// author:			Ryan Zurrin
// file:   		  vect.cpp (XL)

// Implementation for Vector class.

#include "vect.h"   
//#include "Vector3D.h"
using namespace std;
int Vector::object_counter = 0;
Vector::Vector()
{
  x = 0;
  y = 0;  
  magnitude_ = 0.0;
  angle = 0.0;
  calculate_arcLength();
  arcLength = 0.0;
  revolutionAngle_inDegrees = 0.0;
  mode_ = 'r';   
  validate_setMode();  
  object_counter++;
  cout<< object_counter << ": " <<"in the default constructor" <<endl;
}
Vector::Vector(char _mode_)
{	  
  x = 0;
  y = 0;  
  magnitude_ = 0;
  angle = 0;
  calculate_arcLength();
  arcLength = returnAngle();
  revolutionAngle_inDegrees = 0;
  mode_ = _mode_;
  validate_setMode();
  object_counter++;
	cout<< object_counter << ": " <<"in the char constructor"<<endl;;
}
/*______________________________________________________________________________ 
  the third argument is the mode_ setting. 
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/ 
Vector::Vector(ld xMag, ld yAng, char _mode)
{  
  mode_ = _mode;
  setCoordinates(xMag, yAng, _mode);
  object_counter++;
	cout<< object_counter << ": " <<"in the select and set constructor"<<endl;
}
Vector::Vector(const Vector &v)
{
    x=v.x;
    y=v.y;
    calculate_polar();
    object_counter++;
	cout<< object_counter << ": " <<"in the copy constructor"<<endl;
}
void Vector::showAllData()const
{   
  showRectCord();
  showPolarCord();
  showRevolutionAngle();
  returnMode('p');
  returnArcLength('p');
}
void Vector::showVector()const
{
  if (mode_ == 'r' || mode_ == 'R') {
   showRectCord();
   returnArcLength('p');
  }
  else {
   showPolarCord();
   returnArcLength('p');
  }      
}
void Vector::showRectCord()const
{  
	 cout << "\n(x,y) = ";
	
	 if(x < 0 && x > -1 ){
	 	 cout << setiosflags(ios::fixed);
     cout << fixed << "(" << x << "," 
		 << resetiosflags(ios::fixed);      
   }
	 else{  
     cout << "(" << x << ",";               
   }
   if(y<0 && y>-1){
	   cout << setiosflags(ios::fixed);
	   cout << y << ")" <<endl;  
		 cout << resetiosflags(ios::fixed) << endl;  
	 }
	 else{
	 	cout << y << ")" <<endl;
	 }
}
void Vector::showPolarCord()const
{  
	 if(magnitude_ < 0 || angle < 0){
	 cout << setiosflags(ios::fixed);
   cout << "\n<r,\xE9> = <" << magnitude_ << "," << angle << "\xF8>" 
         << endl;
   cout << resetiosflags(ios::fixed) << endl;  
 	 }
 	 else{
 	 	cout << "\n<r,\xE9> = <" << magnitude_ << "," << angle << "\xF8>" 
         << endl;
		}
}
void Vector::showRevolutionAngle()const
{    
  ld temp = 0;
   cout << "\nrevolution degrees:  " << revolutionAngle_inDegrees
         << endl;    
   cout << "full revolutions:    " 
	 			<< static_cast<int>(revolutionAngle_inDegrees/360) << endl;
   if(revolutionAngle_inDegrees < 0){
   cout << "additional degrees:  " << (360 - angle)*(-1) << endl;
   }
   else
   		 cout << "additional degrees:  " << angle << endl; 	
}
/*
void Vector::showPolarCurve()const{
  cout << "\ncartiasian equation of curve is: ";
  cout << "r: " << Curve.r << "  " << "theta: " << Curve.theta << endl;
  cout << "x: " << Curve.x << "  " << "y: " << Curve.y << endl;
}
*/

    /*______________________________________________________________________________
returnX, no arguments or 'r'/'R' will just return, anything else will print out
				 and return.
*/
    ld
    Vector::return_x(char v) const
{
  if (v == 'r' || v == 'R') {
  	return x;    
  } else
  	  cout << "\nx: " << x << endl;
   return 0;     
}
ld Vector::return_y(char v)const
{
  if (v == 'r' || v == 'R') {
  	return y;    
  }
  else
  	cout << "\ny: " << y << endl;
  return 0; 
          
}
ld Vector::return_mag(char v)const
{
  if (v == 'r' || v == 'R') {
  	return magnitude_;     
  } else
  		cout << "\nr: " << magnitude_ << endl;
  	return 0;
      
}
ld Vector::return_angle(char v)const
{
  if (v == 'r' || v == 'R') {
  	return angle;    
  } else
		cout << "\n\xE9: " << angle << "\xF8" << endl;
	return 0;     
}
ld Vector::return_arcLength(char v) const
{
  if (v == 'r' || v == 'R')
  {
    return arcLength;
  } else
    cout << "\narc length: " << arcLength << endl;
  return 0;
}
char Vector::return_mode(char v)const
{
  if (v == 'r' || v == 'R') {
  	return mode_;      
  }
  else
  		if (mode_ == 'p' || mode_ == 'P') {
        cout << "\nmode_: Polar" << endl;     
      } else{
			 cout << "\nmode_: Rectangular" << endl;
      }     
}

/*______________________________________________________________________________
  the third argument is the mode_ setting. 
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/  
void Vector::set_coordinates(ld xMag, ld yAng, char _mode_)
{
  validate_setMode_();

  if (tolower(_mode_) ==  'r') { 
    setRectCord(xMag, yAng); 
    adjust_angle();     
  }        
  else{
      setPolarCord(xMag, yAng);
      adjust_angle();       
  }
  calculate_arcLength();
}
void Vector::set_rectCord(ld _x, ld _y)
{
  x = _x;
  y = _y;
  calculate_polar();
  revolutionAngle_inDegrees = angle;
}

void Vector::set_polarCord(ld mag, ld ang)
{
  magnitude_ = mag;
  validate_magnitude();
  angle =ang;
  revolutionAngle_inDegrees = ang;
  adjust_angle();
  calculate_rectangular(); 
}
void Vector::set_x(ld _x)
{
  x = _x;  
  calculate_polar();
}
void Vector::set_y(ld _y)
{ 
  y = _y;
  calculate_polar();
}
void Vector::set_mag(ld mag)
{  
  magnitude_ = mag; 
  validate_magnitude();
  calculate_rectangular();
  calculate_arcLength();
}
void Vector::set_angle(ld ang)
{  
  angle = ang;
  adjust_angle();
  calculate_arcLength();
  calculate_rectangular();
}
void Vector::set_mode(char _mode)
{
  mode_ = _mode;
  validate_setMode();
}
/*
void Vector::setPolarCurve()
{
	cout << "\nEnter the Polar Curve to convert to cartiesian equation\n>";
	cin >> Curve.r;
  Curve.x = sqrt(pow(Curve.r, 2) + pow(Curve.y, 2));
  Curve.theta = atan(y / x);
}
*/
void Vector::validate_setMode()
{  
	do{
	 	  if (tolower(mode_) == 'r' || tolower(mode_) == 'p') {		 		            
       break;               
 		  }	 	       
  		    else {	          
        cout << "\nEnter a valid mode_, r/R for rectangular\n"
             << "or p/P or polar components\n>";
        cin >> mode_; 
        cin.clear();
        cin.ignore(100, '\n'); 
             } 
  }while(!cin || tolower(mode_) != 'r' || tolower(mode_) != 'p'); 
} 
void Vector::normalize_magnitude()
{
  if (magnitude_ < 0)
    magnitude_ = abs(magnitude_);  
}
void Vector::adjust_angle()
{
  if(angle == -360 || angle == -720 || angle == -1080 || angle == -1440){
  	angle = 0;
  }
	if (angle >= 360){
        auto rev_degrees = static_cast<int>(angle) / 360;
    int to_subtract = rev_degrees *360;
    ld new_angle = angle - to_subtract;
    angle = new_angle;
    }else if (angle < 0 && angle > -360){
    angle += 360;
    cout <<"test:" << angle << endl;
	}else if(angle < -360){
    auto rev_degrees = static_cast<int>(angle) /360;
    int to_subtract = rev_degrees *360;
    ld newAngle = angle - to_subtract + 360;
    angle = newAngle;
  }  
}
void Vector::calculate_rectangular()
{  
  x = magnitude_* cos(angle*RADIAN);
  y = magnitude_* sin(angle*RADIAN);
}
void Vector::calculate_polar()
{	
	 magnitude_ = sqrt(x * x + y * y);     
    if (x == 0.0 && y == 0.0)
        angle = 0.0;
    else
        angle = atan2(y, x)*DEGREE;
    adjust_angle();
    calculate_arcLength();
    revolutionAngle_inDegrees = angle;
}
void Vector::calculate_arcLength()
{
  adjust_angle();
  arcLength = (PI * (magnitude_*2)) *
        (angle / 360.0);
}
/*
Vector Vector::calculate_parallel_vector2d(Vector & v1, Vector & v2)
{
  cout << "in Calc Parallel vec2d: " << endl;
  return Vector(v2.x - v1.x, v2.y - v1.y);
}
*/
bool Vector::operator<(const Vector &v) const
{
  if (magnitude_ < v.magnitude_)
    return true;
  return false;  
}
bool Vector::operator>(const Vector & v)const
{
  if (magnitude_ > v.magnitude_)
    return true;
  return false;
}
bool Vector::operator==(const Vector & v)const
{
  if (magnitude_ == v.magnitude_)
    return true;
  return false;
}

Vector Vector::operator+(const ld n)const
{
	cout << "in  Vector::operator+(const ld n)const"<<endl;
	Vector total(x + n, y + n);
	total.mode_ = mode_;	
	return total;
}
Vector& Vector::operator+=(const Vector& v)
{
    cout << "in Vector& Vector::operator+=(const Vector& v)" << endl;
    Vector sum;
    sum.x += v.x;
    sum.y += v.y;
    sum.mode_ = v.mode_;
    return *this;
}
Vector Vector::operator+(const Vector& v)const
{ 
	cout << "in  Vector::operator+(const Vector& v)const"<<endl;
  Vector sum(x + v.x, y + v.y); 
  sum.mode_ = mode_;  
  return sum;
}

Vector Vector::operator+()const
{ 
	cout << "in  Vector::operator+()const"<<endl;
	Vector total(x+x, y+y);
	total.mode_ = mode_;  
  return total;
}
Vector Vector::operator++()
{
	Vector sum(++x, ++y);
	sum.mode_ = mode_;  
  return sum;
}
Vector Vector::operator++(int)
{ 
  Vector sum(x++, y++, mode_); 
  return sum; 
}
Vector Vector::operator-(const Vector& v)
{ 
  Vector sum(x-v.x, y-v.y, mode_);
  return sum;
}
Vector Vector::operator-(const ld number)const
{
	Vector total(x - number, y - number);  
	total.mode_ = mode_;  
	return total;
}
Vector Vector::operator-()const
{ 
	Vector total(-x, -y);  
	total.mode_ = mode_;
  return total;
}
Vector Vector::operator--()
{
  Vector difference(--x, --y); 
  difference.mode_ = mode_;
  return difference;
}
Vector Vector::operator--(int)
{  
  Vector difference(x--, y--);
  difference.mode_ = mode_;
  return difference; 
}	
Vector operator-(ld s, Vector& v)
{
 Vector total(s-v.returnX(),s-v.return_y(),v.return_mode()); 
 return total;
}
Vector operator+(ld s, Vector& v)
{
 Vector total(s+v.returnX(),s+v.return_y(),v.return_mode()); 
 return total; 
}
Vector &Vector::operator=(const Vector &vec)
{
  x = vec.x;
  y = vec.y;  
  calculate_polar();
  calculate_arcLength();
  return *this;
}
Vector &Vector::operator=(const Vector *vec)
{
  x = vec->x;
  y = vec->y;
  calculate_polar();
  calculate_arcLength();
  return *this;
}
Vector& Vector::operator=(Vector&& right)noexcept
{
     if (this != &right)
     {
         EIGEN_CORE_H::swap(x, right.x);
         EIGEN_CORE_H::swap(y, right.y);
         this->calculate_polar();
     }
     return *this;
}
Vector::Vector(Vector&& temp) noexcept
{
    x = temp.x;
    y = temp.y;  
    mode_ = temp.mode_;
    calculate_polar();
    calculate_arcLength();
    revolutionAngle_inDegrees = returnAngle();
    angle = returnAngle();
    magnitude_ = returnMag();
    arcLength = returnArcLength();     
    calculate_arcLength();   
}
Vector Vector::operator/(ld value)
{
    do {
        if (value != 0)
            return Vector(x / value, y / value);
        else
        {
            do {
                cout << "**ERROR** can't divide by 0, enter new number\n>";
                cin >> value;
                cin.clear();
                cin.ignore(100, '\n');
            } while (!cin || value == 0);
        }
    } while (value > 0 && !cin == false);
}
Vector Vector::operator/=(ld value)
{
    assert(value != 0);
    x /= value;
    y /= value;
    calculate_polar();
    return *this;
}
Vector Vector::operator*(const ld scalar)const
{
	Vector results(x*scaler, y*scalar);	
	results.mode_ = mode_;
	return results;	
}
Vector operator*(ld s, Vector& v)
{
  return v * s;
}
Vector operator*(Vector& v, Vector& s)
{
   Vector results(v.x*s.x, v.y*s.y, v.mode_);	
   return results;
} 
ostream& operator<<(ostream& os, const Vector& v)
{	
  if(v.mode_ == 'R' || v.mode_ == 'r'){
  	v.showRectCord(); 
  }
  else{
  	v.showPolarCord();
  }  
  return os;
} 
istream& operator>>(istream& is, Vector& v)
{
  if(v.mode_ == 'R' || v.mode_ == 'r'){
    is>> v.Curve.r;
    v.calculate_polar();
    v.calculate_rectangular();
  }
  else{
    is>> v.magnitude_ >> v.angle;
    v.calculate_rectangular();
  } 
  return is;
}

Vector::~Vector()
{	
	--object_counter;
	cout << "In Vector destructor : "<< object_counter << " objects remain\n"
			 << endl;
}

