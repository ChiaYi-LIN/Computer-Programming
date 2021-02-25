#include "mylib.h"
int main( int argc, char* args[] )
{
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;
			SDL_Event e;
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );


				SDL_Rect topLeftViewport;
				topLeftViewport.x = 0;
				topLeftViewport.y = 0;
				topLeftViewport.w = SCREEN_WIDTH / 2;
				topLeftViewport.h = SCREEN_HEIGHT / 2;
				SDL_RenderSetViewport( gRenderer, &topLeftViewport );

				SDL_RenderCopy( gRenderer, gTexture[Tsum_1], NULL, NULL );


				SDL_Rect topRightViewport;
				topRightViewport.x = SCREEN_WIDTH / 2;
				topRightViewport.y = 0;
				topRightViewport.w = SCREEN_WIDTH / 2;
				topRightViewport.h = SCREEN_HEIGHT / 2;
				SDL_RenderSetViewport( gRenderer, &topRightViewport );

				SDL_RenderCopy( gRenderer, gTexture[Tsum_2], NULL, NULL );


				SDL_Rect bottomLeftViewport = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
				SDL_RenderSetViewport( gRenderer, &bottomLeftViewport );
				SDL_RenderCopy( gRenderer, gTexture[Tsum_3], NULL, NULL );


				SDL_Rect bottomRightViewport = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
				SDL_RenderSetViewport( gRenderer, &bottomRightViewport );
				SDL_RenderCopy( gRenderer, gTexture[Tsum_4], NULL, NULL );

				SDL_RenderPresent( gRenderer );
			}
		}
	}


	close();

	return 0;
}
