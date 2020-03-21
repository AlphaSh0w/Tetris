#pragma once
#include <vector>
#include <memory>
#include "Colors.h"

typedef Color Tile;

class Shape
{
public:
	enum class Rotation
	{
		up,
		right,
		bottom,
		left
	};
public:
	virtual void RotateLeft() = 0;
	virtual void RotateRight() = 0;
	const std::vector<std::unique_ptr<Tile>>& GetShape();
	//static std::unique_ptr<Shape> GenerateRandomShape(); //to be implemented once the shapes are implemented.

	virtual ~Shape() = default;
protected:
	Shape(int rows, int columns);
private:
	std::vector<std::unique_ptr<Tile>> shape;
	int rows;
	int columns;
	Rotation current_rotation = Rotation::up;
};