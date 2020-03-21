#pragma once
#include <vector>
#include <memory>
#include "Colors.h"

typedef Color Tile;
typedef std::vector<std::unique_ptr<Tile>> RawShape;

class Shape
{
public:
	enum class Rotation
	{
		up = 0,
		right = 1,
		down = 2,
		left = 3
	};
public:
	virtual RawShape GetShapeVersion(Rotation R) const = 0;
	virtual void RotateLeft() = 0;
	virtual void RotateRight() = 0;

	const RawShape& GetRawShape();
	//static std::unique_ptr<Shape> GenerateRandomShape(); //to be implemented once the shapes are implemented.

	virtual ~Shape() = default;
protected:
	Shape(int rows, int columns);
	Rotation current_rotation = Rotation::up;
	RawShape shape;

	static void AssignTilesAt(RawShape& shape_board,std::vector<int> V, Color c); //fills the shapeboard at V positions with color c
private:
	int rows;
	int columns;
	
};

namespace Shapes
{
	class Straight : public Shape
	{
	public:
		Straight();
		RawShape GetShapeVersion(Rotation R) const override;
		void RotateRight() override;
		void RotateLeft() override;

	};

	class Square : public Shape
	{
	public:
		Square();
		RawShape GetShapeVersion(Rotation R) const override;
		void RotateRight() override;
		void RotateLeft() override;
	};

	class Tee : public Shape
	{
	public:
		Tee();
		RawShape GetShapeVersion(Rotation R) const override;
		void RotateRight() override;
		void RotateLeft() override;
	};

	class Jay : public Shape
	{
	public:
		Jay();
		RawShape GetShapeVersion(Rotation R) const override;
		void RotateRight() override;
		void RotateLeft() override;
	};
}