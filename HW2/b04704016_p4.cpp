#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int previousX = 0;
int previousY = 0;

class LTexture
{
	public:
		LTexture();
		~LTexture();
		bool loadFromFile( std::string path );
		void free();
		void render( int x, int y, int width, int height);
		int getWidth();
		int getHeight();
		void setPosition( int x, int y );
		void handleEvent( SDL_Event* e );
		int posiX;
		int posiY;

	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
		SDL_Point mPosition;
};


bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture background;
LTexture dance1;
LTexture dance2;
LTexture dance3;

LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	free();
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
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface( loadedSurface );
	}

	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render( int x, int y, int width, int height)
{
	mWidth = width;
	mHeight = height;
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopyEx( gRenderer, mTexture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}


void LTexture::setPosition( int x, int y )
{
	mPosition.x = x;
	mPosition.y = y;
}

void LTexture::handleEvent( SDL_Event* e )
{
	if( e->button.button == SDL_BUTTON_LEFT && e->type != SDL_MOUSEBUTTONUP )
	{
		int x2, y2;
		SDL_GetMouseState( &x2, &y2 );
		if( previousX == 0 && previousY == 0)
        {
            previousX = x2;
            previousY = y2;
        }
        if( e->type == SDL_MOUSEMOTION )
        {
            posiX = SCREEN_WIDTH/2 - 721/3 + (x2 - previousX);
            posiY = SCREEN_HEIGHT/2  - 340/3 + (y2 - previousY);
        }
        render( posiX, posiY, 721/1.5, 340/1.5);
        if( e->type != SDL_MOUSEMOTION )
        {
            previousX = x2;
            previousY = y2;
        }
	}
}


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
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
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

	if( !background.loadFromFile( "image/background.jpg" ) )
	{
		printf( "Failed to load texture!\n" );
		success = false;
	}
	if( !dance1.loadFromFile( "image/dance1.png" ) )
	{
		printf( "Failed to load texture!\n" );
		success = false;
	}if( !dance2.loadFromFile( "image/dance2.png" ) )
	{
		printf( "Failed to load texture!\n" );
		success = false;
	}
	if( !dance3.loadFromFile( "image/dance3.png" ) )
	{
		printf( "Failed to load texture!\n" );
		success = false;
	}



	return success;
}

void close()
{
	background.free();
	dance1.free();
	dance2.free();
	dance3.free();

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

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
			dance3.posiX = SCREEN_WIDTH/2-721/3;
            dance3.posiY = SCREEN_HEIGHT/2-340/3;
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				background.render(0, 0, 640, 480);


				if(e.type != SDL_MOUSEBUTTONDOWN && e.type != SDL_MOUSEMOTION && e.type != SDL_MOUSEBUTTONUP)
				{
				    dance1.render(SCREEN_WIDTH/2-395/3, SCREEN_HEIGHT/2-519/3, 395/1.5, 519/1.5);
				}
                else if(e.button.button == SDL_BUTTON_LEFT && e.type != SDL_MOUSEBUTTONUP)
                {

                    dance3.handleEvent(&e);

                }
                else
                {
				    dance2.render(SCREEN_WIDTH/2-395/3, SCREEN_HEIGHT/2-519/3, 395/1.5, 519/1.5);
				}

                if( e.button.button != SDL_BUTTON_LEFT )
                {
                        dance3.posiX = SCREEN_WIDTH/2 - 721/3;
                        dance3.posiY = SCREEN_HEIGHT/2  - 340/3;
                }


				SDL_RenderPresent( gRenderer );
			}
		}
	}
	close();

	return 0;
}
