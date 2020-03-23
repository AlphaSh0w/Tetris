#pragma once
#include "Shape.h"
#include "Vect.h"
#include "Graphics.h"
class TileScreen
{
public:
	TileScreen(int x, int y, int tile_dimension, Graphics& gfx);
	TileScreen(Vect<int> origin, int tile_dimension, Graphics& gfx);

	void Draw(Shape& S) const;
	void Draw(const RawShape& S, int rows, int columns) const;

	Vect<int> GetOrigin() const;
	void SetOrigin(Vect<int> new_origin);
public:
	static constexpr int padding = 5;
private:
	Vect<int> origin;
	int tile_dimension;
	Graphics& gfx;
};

