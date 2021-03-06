#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

enum Tsum
{
    Tsum_1,
    Tsum_2,
    Tsum_3,
    Tsum_4,
    Tsum_Total
};

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gTexture[Tsum_Total];

bool init()
{
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		gWindow = SDL_CreateWindow( "b04704016_p2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	gTexture[Tsum_1] = loadTexture( "image/tsum1.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load tsum_1 image!\n" );
		success = false;
	}
	gTexture[Tsum_2] = loadTexture( "image/tsum2.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load tsum_2 image!\n" );
		success = false;
	}
	gTexture[Tsum_3] = loadTexture( "image/tsum3.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load tsum_3 image!\n" );
		success = false;
	}
	gTexture[Tsum_4] = loadTexture( "image/tsum4.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load tsum_4 image!\n" );
		success = false;
	}
	return success;
}

void close()
{

	for(int i = 0; i < Tsum_Total; i++)
	{
        SDL_DestroyTexture( gTexture[i] );
        gTexture[i] = NULL;
	}
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
