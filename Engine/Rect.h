#pragma once
#include "Vect.h"

template <typename T>
class Rect
{
public:
	Rect(const Vect<T>& topleft, const Vect<T>& bottomright)
		:
		topleft(topleft),
		bottomright(bottomright)
	{
	}

	Rect(const Vect<T>& topleft, T x2, T y2)
		:
		Rect(topleft,Vect<T>(x2,y2))
	{
	}

	Rect(T x1, T y1, T x2, T y2)
		:
		Rect(Vect<T>(x1,y1),Vect<T>(x2,y2))
	{
	}
public:
	Vect<T> topleft;
	Vect<T> bottomright;
};

