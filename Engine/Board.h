#pragma once
#include "Shape.h"
#include "TileScreen.h"
#include "Vect.h"
#include "Graphics.h"
class Board
{
public:
	Board(int rows, int columns,Graphics& gfx, int x, int y);

	void DrawContent();
	void DrawCurrentShape();
	void SetTile(Vect<int> pos, std::unique_ptr<Tile> tile);
	void SetTile(int x, int y, std::unique_ptr<Tile> tile);
	bool CheckTemp();
private:
	bool CheckIfPuttable(Shape& S, Vect<int> shape_origin_T);
private:
	static constexpr int tile_dimension = 30;
	static constexpr int default_shape_x = 5;
	static constexpr int default_shape_y = 0;

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