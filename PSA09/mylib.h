#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern bool init();
extern bool loadMedia();
extern void close();
extern SDL_Texture* loadTexture( std::string path );

extern enum Tsum
{
    Tsum_1,
    Tsum_2,
    Tsum_3,
    Tsum_4,
    Tsum_Total
};

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern SDL_Texture* gTexture[Tsum_Total];
