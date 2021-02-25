#include "game.h"



int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set text color as black
			SDL_Color textColor = { 0, 0, 0, 255 };

			//The application timer
			LTimer timer;

			//In memory text stream
			std::stringstream timeText;


            //The dot that will be moving around on the screen
			Dot dot( Dot::DOT_WIDTH / 2, Dot::DOT_HEIGHT / 2 );
			Dot otherDot( SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4 );

			//Set the wall
			SDL_Rect wall = {260, 40, 120, 400};

            timer.start();
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					//Handle input for the dot
					dot.handleEvent( e );

                }

				//Set text to be rendered
				timeText.str( "" );
				timeText << ( timer.getTicks() / 1000.f ) ;

				//Render text
				if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor ) )
				{
					printf( "Unable to render time texture!\n" );
				}

                //Move the dot and check collision
				if(dot.move( wall, otherDot.getCollider() ))
                {
                    timer.pause();
                }
                else
                {
                    timer.unpause();
                }
				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render dots
				dot.render();
				otherDot.render();


				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderDrawRect(gRenderer, &wall);
				//Render textures
				gTimeTextTexture.render( ( SCREEN_WIDTH - gTimeTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTimeTextTexture.getHeight() ) / 2 );
                gWall.render(300, 40);
				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
