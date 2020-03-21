#pragma once
#include <vector>
#include <memory>
#include "Colors.h"

typedef Color Tile;
typedef std::vector<std::unique_ptr<Tile>> ShapeBoard;

class Shape
{
public:
	enum class Rotation
	{
		up,
		right,
		down,
		left
	};
public:
	//virtual void RotateLeft() = 0;
	//virtual void RotateRight() = 0;
	virtual ShapeBoard GetShapeVersion(Rotation R) const = 0;
	const ShapeBoard& GetShape();
	//static std::unique_ptr<Shape> GenerateRandomShape(); //to be implemented once the shapes are implemented.

	virtual ~Shape() = default;
protected:
	Shape(int rows, int columns);
	static void AssignTilesAt(ShapeBoard& shape_board,std::vector<int> V, Color c); //fills the shapeboard at V positions with color c
private:
	ShapeBoard shape;
	int rows;
	int columns;
	Rotation current_rotation = Rotation::up;
	
};

namespace Shapes
{
	class Straight : public Shape
	{
	public:
		Straight();
		ShapeBoard GetShapeVersion(Rotation R) const;
	};
}