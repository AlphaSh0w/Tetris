#include "Shape.h"
#include "Vect.h"
class TileScreen
{
public:
	TileScreen(int x, int y);
	TileScreen(Vect<int> origin);
private:
	Vect<int> origin;
};

TileScreen::TileScreen(int x, int y)
	:
	origin(x,y)
{
}

TileScreen::TileScreen(Vect<int> origin)
	:
	TileScreen(origin.x,origin.y)
{
}
