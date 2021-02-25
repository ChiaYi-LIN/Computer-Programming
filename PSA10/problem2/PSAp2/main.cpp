#include "ShowTime.h"
#include "LTexture.h"
#include <stdio.h>
#include <string>
#include <sstream>



const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;


LTexture gTextTexture;


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }

                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}




void close()
{
    //Free loaded images
    gTextTexture.free();

    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    // Initial window is "00:00"
    int h=0,m=0;

    ShowTime time(h,m);

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        while(1){
            //Load media
            if( !time.loadMedia() )
            {
                printf( "Failed to load media!\n" );
            }
            else
            {
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
                        }else if( e.type == SDL_KEYDOWN )
                        {
                            //Select surfaces based on key press
                            switch( e.key.keysym.sym )
                            {
                                case SDLK_UP:
                                    m+=1;
                                    if(m>=60)
                                    {
                                        m = 0;
                                        h += 1;
                                    }
                                    time.setTime(h,m);
                                    break;
                                    // TODO


                            }

                        }
                        if(h==24)
                        {
                            quit = true;
                        }
                        //Clear screen
                        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                        SDL_RenderClear( gRenderer );

                        //Render current frame
                        gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2 );

                        //Update screen
                        SDL_RenderPresent( gRenderer );
                    }

                }
                break;
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

