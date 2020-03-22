#pragma once

//A vector that holds x and y positions.
template <typename T>
class Vect
{
public:
	//constructors
	Vect() = default;
	Vect(T x, T y)
		:x(x),
		y(y)
	{}

	//operators overload
	Vect operator+ (const Vect& rhs) const
	{
		return Vect(x + rhs.x, y + rhs.y);
	}
	Vect& operator+= (const Vect& rhs)
	{
		return *this = *this + rhs;
	}
	Vect operator- (const Vect& rhs) const
	{
		return Vect(x - rhs.x, y - rhs.y);
	}
	Vect& operator-=(const Vect& rhs)
	{
		return *this = *this - rhs;
	}
	Vect operator* (const Vect& rhs) const
	{
		return Vect(x * rhs.x, y * rhs.y);
	}
	Vect& operator*= (const Vect& rhs)
	{
		return *this = *this * rhs;
	}
	Vect operator* (T rhs) const
	{
		return Vect(x * rhs, y * rhs);
	}
	Vect operator/ (const Vect& rhs) const
	{
		return Vect(x / rhs.x, y / rhs.y);
	}
	Vect& operator/= (const Vect& rhs)
	{
		return *this = *this / rhs;
	}

public:
	T x;
	T y;
};