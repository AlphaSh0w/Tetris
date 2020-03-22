#pragma once
#include "Shape.h"
#include "Vect.h"
class TileScreen
{
public:
	TileScreen(int x, int y);
	TileScreen(Vect<int> origin);
private:
	Vect<int> origin;
};

