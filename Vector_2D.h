#pragma once
class Vector_2D
{
public :
	//Constructor
	Vector_2D(float x, float y);

	//variables for the axis
	float x();
	float y();

	// function to make velocity
	void operator = (Vector_2D rhs);
	void operator +=(Vector_2D rhs);

	Vector_2D operator-(Vector_2D rhs);
	Vector_2D operator+(Vector_2D rhs);
	void scale(float scalar);

	float magnitude();
	void normalize();
	float angle();

private:
	float _x;
	float _y;

};

