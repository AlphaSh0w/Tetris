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
	virtual void RotateLeft();
	virtual void RotateRight();
	Rotation GetCurrentRotation();
	const RawShape& GetRawShape() const;
	int GetNumberOfRows() const;
	int GetNumberOfColumns() const;
	virtual ~Shape() = default;
	std::unique_ptr<Tile>& operator[](int index);
	static std::unique_ptr<Shape> GenerateRandomShape();
	Rotation GetLeftRotationDirection();
	Rotation GetRightRotationDirection();
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
	};

	class Square : public Shape
	{
	public:
		Square();
		RawShape GetShapeVersion(Rotation R) const override;
	};

	class Tee : public Shape
	{
	public:
		Tee();
		RawShape GetShapeVersion(Rotation R) const override;
	};

	class Jay : public Shape
	{
	public:
		Jay();
		RawShape GetShapeVersion(Rotation R) const override;
	};

	class El : public Shape
	{
	public:
		El();
		RawShape GetShapeVersion(Rotation R) const override;
	};

	class SkewS : public Shape
	{
	public:
		SkewS();
		RawShape GetShapeVersion(Rotation R) const override;
	};

	class SkewZ : public Shape
	{
	public:
		SkewZ();
		RawShape GetShapeVersion(Rotation R) const override;
	};
}