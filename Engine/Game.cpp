/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	tilescren(50, 50, 35, gfx),
	board(10,15,gfx,100,100)
{
	shapeptr = Shape::GenerateRandomShape();
	board.SetTile(0, 0, std::make_unique<Tile>(Colors::Blue));
	board.SetTile(14, 0, std::make_unique<Tile>(Colors::Blue));
	board.SetTile(0, 9, std::make_unique<Tile>(Colors::Blue));
	board.SetTile(14, 9, std::make_unique<Tile>(Colors::Blue));
	board.SetTile(1, 6, std::make_unique<Tile>(Colors::Red));
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	board.CheckTemp();
	while (!wnd.kbd.KeyIsEmpty())
	{
		const auto e = wnd.kbd.ReadKey();
		if (e.IsPress() && e.GetCode() == 'W')
		{
			shapeptr->RotateLeft();
		}
		if (e.IsPress() && e.GetCode() == 'X')
		{
			shapeptr->RotateRight();
		}
	}
}

void Game::ComposeFrame()
{
	tilescren.Draw(*shapeptr);
	board.DrawContent();
	board.DrawCurrentShape();
}
