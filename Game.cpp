#include "stdafx.h"
#include "Game.h"
#include "Texture.h"
Texture Game::m_StatDaeTexture{ "./Resources/DAE.png"};
Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	TestContainer();

}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
}

void Game::Draw( )
{
	ClearBackground( );
	m_StatDaeTexture.Draw(Point2f{ 0.0f,50.0f });
	DrawTexture(m_DaeTexture, { 0,200.0f }, 4, 20, 20);

}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( )
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DrawTexture( const Texture& texture , const Point2f & pos, int nr, int dx, int dy)
{
	for (int i{ 0 }; i < nr; ++i)
	{
		texture.Draw(Point2f{ pos.x + i * dx, pos.y + i * dy });

	}
}

void Game::TestContainer()
{
	Container c1{};
	AddValues(c1, 3, 1, 10);

	Container c2{ c1 };
	c1[0] = 20;

	Container c3{ 3 };
	AddValues(c3,3,10,20);
	c3 = c1;

	c3 = c3;

// c3 = 4;

	Container c4 = {};
	//c4 = CreateMultiplied(c1, 2);
	AddValues(c4, 3, 20, 30);

}

void Game::AddValues(Container & c, int nr, int min, int max)
{
	for (int i{ 0 }; i < nr; i++)
	{
		c.PushBack(rand() % (max - min + 1) + min);
	}

}

Container Game::CreateMultiplied(Container c, int factor)
{
	for (int idx{ 0 }; idx < c.Size(); ++idx)
	{
		c[idx] *= factor;
	}
	return c;
}
