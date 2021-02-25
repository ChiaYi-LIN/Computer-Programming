#include <SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Current displayed image
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gAvenue = NULL;
SDL_Surface* gLibrary = NULL;
SDL_Surface* gGym = NULL;
SDL_Surface* gShinemood = NULL;
SDL_Surface* gGate = NULL;
SDL_Surface* gCurrentSurface = NULL;

bool init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "b04704016_p2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}


bool loadMedia()
{
    bool success = true;

    gAvenue = SDL_LoadBMP( "image/Avenue.bmp" );
    if( gAvenue == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image/Avenue.bmp", SDL_GetError() );
        success = false;
    }

    gLibrary = SDL_LoadBMP( "image/Library.bmp" );
    if( gLibrary == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image/Library.bmp", SDL_GetError() );
        success = false;
    }

    gGym = SDL_LoadBMP( "image/Gym.bmp" );
    if( gLibrary == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image/Gym.bmp", SDL_GetError() );
        success = false;
    }

    gShinemood = SDL_LoadBMP( "image/Shinemood.bmp" );
    if( gLibrary == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image/Shinemood.bmp", SDL_GetError() );
        success = false;
    }

    gGate = SDL_LoadBMP( "image/Gate.bmp" );
    if( gLibrary == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "image/Gate.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}


void close()
{
    SDL_FreeSurface( gAvenue );
    gAvenue = NULL;
    SDL_FreeSurface( gLibrary );
    gLibrary = NULL;
    SDL_FreeSurface( gGym );
    gGym = NULL;
    SDL_FreeSurface( gShinemood );
    gShinemood = NULL;
    SDL_FreeSurface( gGate );
    gGate = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}


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
            //Apply the image
            SDL_BlitSurface( gAvenue, NULL, gScreenSurface, NULL );


            //Update the surface
            SDL_UpdateWindowSurface( gWindow );


            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

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
                    else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{
							case SDLK_UP:
							gCurrentSurface = gLibrary;
							break;

							case SDLK_DOWN:
							gCurrentSurface = gGate;
							break;

							case SDLK_LEFT:
							gCurrentSurface = gGym;
							break;

							case SDLK_RIGHT:
							gCurrentSurface = gShinemood;
							break;

							case SDLK_q:
                            quit = true;
                            break;

							default:
							gCurrentSurface = gAvenue;
							break;
						}
                    }
                }

                //Apply the current image
				SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );




            }
        }
    }
    close();

    return 0;
}











