#include "Shape.h"
#include <assert.h>

const std::vector<std::unique_ptr<Tile>>& Shape::GetShape()
{
	return shape;
}

Shape::Shape(int rows, int columns)
	:
	rows(rows),
	columns(columns)
{
	assert(rows > 0 && columns > 0); //If assertion fails: the constructor was given negative values.
	shape.resize(rows * columns);
}
