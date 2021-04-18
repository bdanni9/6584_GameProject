#include "Vector_2D.h"

#include <math.h>

Vector_2D::Vector_2D(float x, float y)
{
	_x = x;
	_y = y;
}

float Vector_2D::x()
{
	return _x;
}

float Vector_2D::y()
{
	return _y;
}

void Vector_2D::operator=(Vector_2D rhs)
{
	_x = rhs._x;
	_y = rhs._y;
}

void Vector_2D::operator+=(Vector_2D rhs)
{	
	//a=b; a is the vector b
	_x += rhs._x;
	_y += rhs._y;
}

Vector_2D Vector_2D::operator-(Vector_2D rhs)
{
	//a=b-a; a is the magnitude
	return Vector_2D(_x - rhs._x,_y -rhs._y);
}

Vector_2D Vector_2D::operator+(Vector_2D rhs)
{
	// a=a+a; is the velocity
	return Vector_2D(_x+rhs._x,_y +rhs._y);
}

void Vector_2D::scale(float scalar)
{
	//a=+b; a is added to vector b
	_x *= scalar;
	_y *= scalar;
}

float Vector_2D::magnitude()
{
	return sqrtf(_x*_x+_y*_y);
}

void Vector_2D::normalize()
{
	float mag = magnitude();

	if (mag > 0.0f)
	{
		_x /= mag;
		_y /= mag;
	}
}

float Vector_2D::angle()
{
	return -atan2f(_y, _x);
}
