#include "Board.h"
#include <assert.h>

Board::Board(int rows, int columns, Graphics& gfx,int x, int y)
	:
	rows(rows),
	columns(columns),
	content_screen(x,y,tile_dimension,gfx),
	current_shape_screen(default_shape_x,default_shape_y,tile_dimension,gfx)
{
	assert(rows > 0 && columns > 0); //If assertion fails : rows or columns value is <= 0
	content.resize(rows * columns);
	current_shape = Shape::GenerateRandomShape();
	next_shape = Shape::GenerateRandomShape();
}



void Board::SetTile(Vect<int> pos, std::unique_ptr<Tile> tile)
{
	assert(pos.x <= columns);//assertion : x bigger than the number of columns.
	assert(pos.y <= rows);//assertion : y bigger than the number of rows.

	int index = pos.y * rows + pos.x;
	content[index] = std::move(tile);
}

void Board::SetTile(int x, int y, std::unique_ptr<Tile> tile)
{
	SetTile(Vect<int>(x,y), std::move(tile));
}
