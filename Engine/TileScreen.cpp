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

void TileScreen::Draw(const RawShape & S, int rows, int columns) const
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			int index = r * columns + c;
			if (S[index] != nullptr)
			{
				Vect<int> topleft = { tile_dimension * c + origin.x + padding, tile_dimension * r + origin.y + padding };
				Vect<int> bottomright = { topleft.x + tile_dimension - padding, topleft.y + tile_dimension - padding };
				gfx.DrawRect(topleft, bottomright, *S[index]);
			}
		}
	}
}

void TileScreen::Draw(Shape & S) const
{
	Draw(S.GetRawShape(), S.GetNumberOfRows(), S.GetNumberOfColumns());
}


Vect<int> TileScreen::GetOrigin() const
{
	return origin;
}

void TileScreen::SetOrigin(Vect<int> new_origin)
{
	origin = new_origin;
}


