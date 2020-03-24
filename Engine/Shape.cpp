#include "Shape.h"
#include <assert.h>
#include <random>

void Shape::RotateLeft()
{
	current_rotation = GetLeftRotationDirection();
	shape = GetShapeVersion(current_rotation);
}

void Shape::RotateRight()
{
	shape = GetShapeVersion(GetRightRotationDirection());
}

Shape::Rotation Shape::GetCurrentRotation()
{
	return current_rotation;
}

const std::vector<std::unique_ptr<Tile>>& Shape::GetRawShape() const
{
	return shape;
}

std::unique_ptr<Shape> Shape::GenerateRandomShape()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> shape_dist(0, 6);
	switch (shape_dist(rng))
	{
	case 0:
		return std::make_unique<Shapes::Straight>();
		break;
	case 1:
		return std::make_unique<Shapes::Square>();
		break;
	case 2:
		return std::make_unique<Shapes::Tee>();
		break;
	case 3:
		return std::make_unique<Shapes::Jay>();
		break;
	case 4:
		return std::make_unique<Shapes::El>();
		break;
	case 5:
		return std::make_unique<Shapes::SkewS>();
		break;
	case 6:
		return std::make_unique<Shapes::SkewZ>();
		break;
	default:
		assert(false); //Assertion fail: something is wrong with the rng.
		return nullptr;
		break;
	}
}

Shape::Rotation Shape::GetLeftRotationDirection()
{
	return (Rotation)(((int)current_rotation + 1) % 4);
}

Shape::Rotation Shape::GetRightRotationDirection()
{
	int int_rotation = (int)current_rotation - 1;
	if (int_rotation < 0)
	{
		 return (Rotation)3;
	}
	else
	{
		return (Rotation)int_rotation;
	}
}

int Shape::GetNumberOfRows() const
{
	return rows;
}

int Shape::GetNumberOfColumns() const
{
	return columns;
}

std::unique_ptr<Tile>& Shape::operator[](int index)
{
	return shape[index];
}

Shape::Shape(int rows, int columns)
	:
	rows(rows),
	columns(columns)
{
	assert(rows > 0 && columns > 0); //If assertion fails: the constructor was given negative values.
	shape.resize(rows * columns);
}

void Shape::AssignTilesAt(RawShape& shape_board,std::vector<int> V, Color c)
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
	shape = GetShapeVersion(Rotation::up);
}

RawShape Shapes::Straight::GetShapeVersion(Rotation R) const
{
	RawShape temp = RawShape();
	temp.resize(4 * 4);
	//filling the right shape.
	Color c = Colors::Blue;
	switch (R)
	{
	case Rotation::up:
		AssignTilesAt(temp, {4,5,6,7}, c);
		break;
	case Rotation::right:
		AssignTilesAt(temp, { 2,6,10,14 }, c);
		break;
	case Rotation::down:
		AssignTilesAt(temp, { 8,9,10,11 }, c);
		break;
	case Rotation::left:
		AssignTilesAt(temp, { 1,5,9,13 }, c);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
		break;
	}
	return std::move(temp);
}

Shapes::Square::Square()
	:
	Shape(2,2)
{
	shape = GetShapeVersion(Rotation::up);
}

RawShape Shapes::Square::GetShapeVersion(Rotation R) const
{
	RawShape temp = RawShape();
	temp.resize(2 * 2);
	//filling the right shape.
	assert((int)R == 0 || (int)R == 1 || (int)R == 2 || (int)R == 3); //if assertion fails: Rotation does not exist (values from 0 to 3 only).
	AssignTilesAt(temp, { 0,1,2,3 }, Colors::Yellow);
	return std::move(temp);
}

Shapes::Tee::Tee()
	:
	Shape(3,3)
{
	shape = GetShapeVersion(Rotation::up);
}

RawShape Shapes::Tee::GetShapeVersion(Rotation R) const
{
	RawShape temp = RawShape();
	temp.resize(3 * 3);
	//filling the right shape.
	Color c = Colors::Magenta;
	switch (R)
	{
	case Rotation::up:
		AssignTilesAt(temp, { 1,3,4,5 }, c);
		break;
	case Rotation::right:
		AssignTilesAt(temp, { 1,4,5,7 }, c);
		break;
	case Rotation::down:
		AssignTilesAt(temp, { 3,4,5,7 }, c);
		break;
	case Rotation::left:
		AssignTilesAt(temp, { 1,3,4,7 }, c);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
		break;
	}
	return std::move(temp);
}

Shapes::Jay::Jay()
	:
	Shape(3,3)
{
	shape = GetShapeVersion(Rotation::up);
}

RawShape Shapes::Jay::GetShapeVersion(Rotation R) const
{
	RawShape temp = RawShape();
	temp.resize(3 * 3);
	//filling the right shape.
	Color c = Colors::Cyan;
	switch (R)
	{
	case Rotation::up:
		AssignTilesAt(temp, { 0,3,4,5 }, c);
		break;
	case Rotation::right:
		AssignTilesAt(temp, { 1,2,4,7 }, c);
		break;
	case Rotation::down:
		AssignTilesAt(temp, { 3,4,5,8 }, c);
		break;
	case Rotation::left:
		AssignTilesAt(temp, { 1,4,6,7 }, c);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
		break;
	}
	return std::move(temp);
}

Shapes::El::El()
	:
	Shape(3,3)
{
	shape = GetShapeVersion(Rotation::up);
}

RawShape Shapes::El::GetShapeVersion(Rotation R) const
{
	RawShape temp = RawShape();
	temp.resize(3 * 3);
	//filling the right shape.
	Color c = Color(255, 162, 0); //orange color
	switch (R)
	{
	case Rotation::up:
		AssignTilesAt(temp, { 2,3,4,5 }, c);
		break;
	case Rotation::right:
		AssignTilesAt(temp, { 1,4,7,8 }, c);
		break;
	case Rotation::down:
		AssignTilesAt(temp, { 3,4,5,6 }, c);
		break;
	case Rotation::left:
		AssignTilesAt(temp, { 0,1,4,7 }, c);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
		break;
	}
	return std::move(temp);
}

Shapes::SkewS::SkewS()
	:
	Shape(3,3)
{
	shape = GetShapeVersion(Rotation::up);
}

RawShape Shapes::SkewS::GetShapeVersion(Rotation R) const
{
	RawShape temp = RawShape();
	temp.resize(3 * 3);
	//filling the right shape.
	Color c = Colors::Green; //orange color
	switch (R)
	{
	case Rotation::up:
		AssignTilesAt(temp, { 1,2,3,4 }, c);
		break;
	case Rotation::right:
		AssignTilesAt(temp, { 1,4,5,8 }, c);
		break;
	case Rotation::down:
		AssignTilesAt(temp, { 4,5,6,7 }, c);
		break;
	case Rotation::left:
		AssignTilesAt(temp, { 0,3,4,7 }, c);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
		break;
	}
	return std::move(temp);
}

Shapes::SkewZ::SkewZ()
	:
	Shape(3,3)
{
	shape = GetShapeVersion(Rotation::up);
}

RawShape Shapes::SkewZ::GetShapeVersion(Rotation R) const
{
	RawShape temp = RawShape();
	temp.resize(3 * 3);
	//filling the right shape.
	Color c = Colors::Red; //orange color
	switch (R)
	{
	case Rotation::up:
		AssignTilesAt(temp, { 0,1,4,5 }, c);
		break;
	case Rotation::right:
		AssignTilesAt(temp, { 2,4,5,7 }, c);
		break;
	case Rotation::down:
		AssignTilesAt(temp, { 3,4,7,8 }, c);
		break;
	case Rotation::left:
		AssignTilesAt(temp, { 1,3,4,6 }, c);
		break;
	default:
		assert(false); //assertion: Rotation does not exist (values from 0 to 3 only).
		break;
	}
	return std::move(temp);
}