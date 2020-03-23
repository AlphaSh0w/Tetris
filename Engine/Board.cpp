#include "Board.h"
#include <assert.h>

Board::Board(int rows, int columns, Graphics& gfx,int x, int y)
	:
	rows(rows),
	columns(columns),
	content_screen(x,y,tile_dimension,gfx),
	current_shape_screen(x + (default_shape_x * tile_dimension),y + (default_shape_y * tile_dimension),tile_dimension,gfx),
	shape_origin_T(5,0)
{
	assert(rows > 0 && columns > 0); //If assertion fails : rows or columns value is <= 0
	content.resize(rows * columns);
	current_shape = Shape::GenerateRandomShape();
	next_shape = Shape::GenerateRandomShape();
}

void Board::DrawContent()
{
	content_screen.Draw(content, rows, columns);
}

void Board::DrawCurrentShape()
{
	current_shape_screen.Draw(current_shape->GetRawShape(), current_shape->GetNumberOfRows(), current_shape->GetNumberOfRows());
}


void Board::SetTile(Vect<int> pos, std::unique_ptr<Tile> tile)
{
	assert(pos.x < columns);//assertion : x bigger than the number of columns.
	assert(pos.y < rows);//assertion : y bigger than the number of rows.

	int index = pos.y * rows + pos.x;
	content[index] = std::move(tile);
}

void Board::SetTile(int x, int y, std::unique_ptr<Tile> tile)
{
	SetTile(Vect<int>(x,y), std::move(tile));
}

bool Board::CheckTemp()
{
	return CheckIfPuttable(*current_shape, shape_origin_T);
}

bool Board::CheckIfPuttable(Shape & S, Vect<int> shape_origin_T)
{
	for(int r = 0; r < S.GetNumberOfRows();r++)
	{
		for (int c = 0; c < S.GetNumberOfColumns(); c++)
		{
			int content_index = (shape_origin_T.y + r) * columns + (c + shape_origin_T.x);
			int shape_index = r * S.GetNumberOfColumns() + c;
			if (S[shape_index] != nullptr && content[content_index] != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
