#pragma once
#include "Shape.h"
#include "TileScreen.h"
#include "Vect.h"
#include "Graphics.h"
class Board
{
public:
	Board(Vect<int> pos,Graphics& gfx, int x, int y);

	void DrawContent() const;
	void DrawCurrentShape() const;
	void SetTile(Vect<int> pos, std::unique_ptr<Tile> tile);
	bool CheckTemp();//temporary public acces to CheckIfPuttable function with the current shape.
	void RotateShapeLeft();
	void RotateShapeRight();
	void ShiftCurrentShapeToLeft();
	void ShiftCurrentShapeToRight();
	void ShiftCurrentShapeDown();
	bool IsCurrentShiftableLeft();
	bool IsCurrentShiftableRight();
private:
	bool CheckIfPuttable(Shape& S, Vect<int> shape_origin_T);
private:
	static constexpr int tile_dimension = 30;
	static constexpr int default_shape_x_T = 5;
	static constexpr int default_shape_y_T = 0;

private:
	RawShape content;
	Vect<int> shape_origin_T; //T means "in tiles", the values are the number of tiles, not pixels.
	TileScreen content_screen;
	TileScreen current_shape_screen;
	int rows;
	int columns;

	std::unique_ptr<Shape> current_shape;
	std::unique_ptr<Shape> next_shape;
};