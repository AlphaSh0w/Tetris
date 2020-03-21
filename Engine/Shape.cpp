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

Shapes::Straight::Straight()
	:
	Shape(4,4)
{
}

ShapeBoard Shapes::Straight::GetShapeVersion(Rotation R) const
{
	ShapeBoard temp = ShapeBoard();
	temp.resize(4 * 4);
	//filling the right shape.

	switch (R)
	{
	case Rotation::up:
		temp[4] = std::make_unique<Tile>(Colors::Blue);
		temp[5] = std::make_unique<Tile>(Colors::Blue);
		temp[6] = std::make_unique<Tile>(Colors::Blue);
		temp[7] = std::make_unique<Tile>(Colors::Blue);
		break;
	case Rotation::right:
		temp[2] = std::make_unique<Tile>(Colors::Blue);
		temp[6] = std::make_unique<Tile>(Colors::Blue);
		temp[10] = std::make_unique<Tile>(Colors::Blue);
		temp[14] = std::make_unique<Tile>(Colors::Blue);
		break;
	case Rotation::down:
		temp[8] = std::make_unique<Tile>(Colors::Blue);
		temp[9] = std::make_unique<Tile>(Colors::Blue);
		temp[10] = std::make_unique<Tile>(Colors::Blue);
		temp[11] = std::make_unique<Tile>(Colors::Blue);
		break;
	case Rotation::left:
		temp[1] = std::make_unique<Tile>(Colors::Blue);
		temp[5] = std::make_unique<Tile>(Colors::Blue);
		temp[9] = std::make_unique<Tile>(Colors::Blue);
		temp[13] = std::make_unique<Tile>(Colors::Blue);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
	}
	return std::move(temp);
}

