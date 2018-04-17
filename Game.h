#pragma once
#include "Container.h"
#include "Texture.h"
class Game
{
public:
	explicit Game( const Window& window );
	Game( const Game& other ) = delete;
	Game& operator=( const Game& other ) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( );

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );
	



private:
	// DATA MEMBERS
	Window m_Window;
	static Texture m_StatDaeTexture;
	Texture m_DaeTexture{ "./Resources/DAE.png" };

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( );
	void DrawTexture(const Texture& texture, const Point2f &pos, int nr, int dx, int dy);
	// Container Functions
	void TestContainer();
	void AddValues(Container &c, int nr, int min, int max);
	Container CreateMultiplied(Container c, int factor);


};