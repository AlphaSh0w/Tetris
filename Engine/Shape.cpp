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

void Shape::AssignTilesAt(ShapeBoard& shape_board,std::vector<int> V, Color c)
{
	for (int v : V)
	{
		shape_board[v] = std::make_unique<Color>(c);
	}
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
		AssignTilesAt(temp, {4,5,6,7}, Colors::Blue);
		break;
	case Rotation::right:
		AssignTilesAt(temp, { 2,6,10,14 }, Colors::Blue);
		break;
	case Rotation::down:
		AssignTilesAt(temp, { 8,9,10,11 }, Colors::Blue);
		break;
	case Rotation::left:
		AssignTilesAt(temp, { 1,5,9,13 }, Colors::Blue);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
	}
	return std::move(temp);
}

void Shapes::Straight::RotateRight()
{
	current_rotation = (Rotation)( ( (int)current_rotation + 1) %4);
	shape = GetShapeVersion(current_rotation);

}

void Shapes::Straight::RotateLeft()
{
	current_rotation = (Rotation)((std::abs((int)current_rotation - 1)) % 4);
	shape = GetShapeVersion(current_rotation);
}

