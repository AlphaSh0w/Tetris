#include "TileScreen.h"

TileScreen::TileScreen(int x, int y, int tile_dimension, Graphics& gfx)
	:
	origin(x, y),
	tile_dimension(tile_dimension),
	gfx(gfx)
{
}

TileScreen::TileScreen(Vect<int> origin, int tile_dimension, Graphics& gfx)
	:
	TileScreen(origin.x, origin.y,tile_dimension,gfx)
{
}

void TileScreen::Draw(Shape & S) const
{
	const RawShape& temp = S.GetRawShape();
	for (int rows = 0; rows < S.GetNumberOfRows(); rows++)
	{
		for (int columns = 0; columns < S.GetNumberOfColumns(); columns++)
		{
			int index = rows * S.GetNumberOfColumns() + columns;
			if (temp[index] != nullptr)
			{
				Vect<int> topleft = { tile_dimension * columns + origin.x + padding, tile_dimension * rows + origin.y + padding };
				Vect<int> bottomright = { topleft.x + tile_dimension - padding, topleft.y + tile_dimension - padding};
				gfx.DrawRect(topleft, bottomright, *temp[index]);
			}
		}
	}
}

Vect<int> TileScreen::GetOrigin() const
{
	return origin;
}

void TileScreen::SetOrigin(Vect<int> new_origin)
{
	origin = new_origin;
}


