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
	board(Vect<int>(10,18),gfx,200,50)
{
	wnd.kbd.EnableAutorepeat();
	//board.SetTile(Vect<int>(6, 4), std::make_unique<Tile>(Colors::Blue));
	//board.SetTile(0, 9, std::make_unique<Tile>(Colors::Blue));
	//board.SetTile(14, 9, std::make_unique<Tile>(Colors::Blue));
	//board.SetTile(1, 6, std::make_unique<Tile>(Colors::Red));
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
	if (!board.CheckIfLost())
	{
		while (!wnd.kbd.KeyIsEmpty())
		{
			const auto e = wnd.kbd.ReadKey();
			if (e.IsPress() && e.GetCode() == 'W')
			{
				if (board.IsCurrentRotatableLeft())
				{
					board.RotateShapeLeft();
				}
			}
			if (e.IsPress() && e.GetCode() == 'X')
			{
				if (board.IsCurrentRotatableRight())
				{
					board.RotateShapeRight();
				}
			}
			if (e.IsPress() && e.GetCode() == VK_LEFT)
			{
				if (board.IsCurrentShiftableLeft())
				{
					board.ShiftCurrentShapeToLeft();
				}
			}
			if (e.IsPress() && e.GetCode() == VK_RIGHT)
			{
				if (board.IsCurrentShiftableRight())
				{
					board.ShiftCurrentShapeToRight();
				}
			}
			if (e.IsPress() && e.GetCode() == VK_DOWN)
			{
				passed_frames = 0;
				if (board.Next())
				{
					next_frame_time = std::max(min_frame_time, next_frame_time - frame_time_drain);
					wnd.kbd.DisableAutorepeat();
				}
			}
			if (e.IsRelease() && e.GetCode() == VK_DOWN)
			{
				wnd.kbd.Flush();
				wnd.kbd.EnableAutorepeat();
			}
		}
		if (passed_frames > (int)next_frame_time)
		{
			if (board.Next())
			{
				next_frame_time = std::max(min_frame_time, next_frame_time - frame_time_drain);
			}
			passed_frames = 0;
		}
		++passed_frames;
	}
}

void Game::ComposeFrame()
{
	board.DrawContent();
	board.DrawCurrentShape();
}
