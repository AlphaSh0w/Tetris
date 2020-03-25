#include "Board.h"
#include <assert.h>

Board::Board(Vect<int> dimension, Graphics& gfx,int x, int y)
	:
	rows(dimension.y),
	columns(dimension.x),
	content_screen(x,y,tile_dimension,gfx),
	current_shape_screen(x + (default_shape_x_T * tile_dimension),y + (default_shape_y_T * tile_dimension),tile_dimension,gfx),
	shape_origin_T(5,0)
{
	assert(rows > 0 && columns > 0); //If assertion fails : rows or columns value is <= 0
	content.resize(rows * columns);
	current_shape = Shape::GenerateRandomShape();
	next_shape = Shape::GenerateRandomShape();
}

void Board::DrawContent() const
{
	content_screen.Draw(content, rows, columns);
}

void Board::DrawCurrentShape() const
{
	current_shape_screen.Draw(current_shape->GetRawShape(), current_shape->GetNumberOfRows(), current_shape->GetNumberOfColumns());
}


void Board::SetTile(Vect<int> pos, std::unique_ptr<Tile> tile)
{
	assert(pos.x < columns);//assertion : x bigger than the number of columns.
	assert(pos.y < rows);//assertion : y bigger than the number of rows.

	int index = pos.y * columns + pos.x;
	content[index] = std::move(tile);
}

bool Board::CheckTemp()
{
	return CheckIfPuttable(*current_shape, shape_origin_T);
}

void Board::RotateShapeLeft()
{
	current_shape->RotateLeft();
}

void Board::RotateShapeRight()
{
	current_shape->RotateRight();
}

void Board::ShiftCurrentShapeToLeft()
{
	shape_origin_T += Vect<int>(-1, 0);
	current_shape_screen.ShiftLeft();
}

void Board::ShiftCurrentShapeToRight()
{
	shape_origin_T += Vect<int>(1, 0);
	current_shape_screen.ShiftRight();
}

void Board::ShiftCurrentShapeDown()
{
	shape_origin_T += Vect<int>(0, 1);
	current_shape_screen.ShiftDown();
}

bool Board::IsCurrentShiftableLeft() const
{
	return CheckIfPuttable(*current_shape,shape_origin_T + Vect<int>(-1,0));
}

bool Board::IsCurrentShiftableRight() const
{
	return CheckIfPuttable(*current_shape, shape_origin_T + Vect<int>(1, 0));
}

bool Board::IsCurrentRotatableLeft() const
{
	return CheckIfPuttable(current_shape->GetShapeVersion(current_shape->GetLeftRotationDirection()),
		current_shape->GetNumberOfRows(),current_shape->GetNumberOfColumns(),shape_origin_T);
}

bool Board::IsCurrentRotatableRight() const
{
	return CheckIfPuttable(current_shape->GetShapeVersion(current_shape->GetRightRotationDirection()),
		current_shape->GetNumberOfRows(), current_shape->GetNumberOfColumns(), shape_origin_T);
}

void Board::PutCurrentShapeToContent()
{
	for (int r = 0; r < current_shape->GetNumberOfRows(); r++)
	{
		for (int c = 0; c < current_shape->GetNumberOfColumns(); c++)
		{

			int shape_index = r * current_shape->GetNumberOfColumns() + c;
			if ((*current_shape)[shape_index] != nullptr)
			{
				int content_index = (shape_origin_T.y + r) * columns + (c + shape_origin_T.x);
				content[content_index] = std::move((*current_shape)[shape_index]);
			}
		}
	}
}

void Board::GenerateNewShape()
{
	current_shape = std::move(next_shape);
	next_shape = Shape::GenerateRandomShape();
}



bool Board::CheckIfPuttable(const RawShape & S,int row, int column, Vect<int> shape_origin_T) const
{
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < column; c++)
		{
			int content_index = (shape_origin_T.y + r) * columns + (c + shape_origin_T.x);
			int shape_index = r * column + c;
			if (S[shape_index] != nullptr)
			{
				if ((shape_origin_T.x + c > columns || shape_origin_T.y + r > rows ||
					shape_origin_T.x + c < 0 || shape_origin_T.y + r < 0) || content[content_index] != nullptr)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Board::CheckIfPuttable(Shape & S, Vect<int> shape_origin_T) const
{
	return CheckIfPuttable(S.GetRawShape(), S.GetNumberOfRows(), S.GetNumberOfColumns(), shape_origin_T);
}
