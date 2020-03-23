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
	void SetTile(Vect<int> pos, std::unique_ptr<Tile> tile);
	void SetTile(int x, int y, std::unique_ptr<Tile> tile);
private:

	static constexpr int tile_dimension = 35;
	static constexpr int default_shape_x = 5;
	static constexpr int default_shape_y = 0;

private:
	RawShape content;
	Vect<int> shape_origin_T;
	TileScreen content_screen;
	TileScreen current_shape_screen;
	int rows;
	int columns;

	std::unique_ptr<Shape> current_shape;
	std::unique_ptr<Shape> next_shape;
};