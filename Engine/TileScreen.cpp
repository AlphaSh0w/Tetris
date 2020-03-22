#include "TileScreen.h"

TileScreen::TileScreen(int x, int y)
	:
	origin(x, y)
{
}

TileScreen::TileScreen(Vect<int> origin)
	:
	TileScreen(origin.x, origin.y)
{
}