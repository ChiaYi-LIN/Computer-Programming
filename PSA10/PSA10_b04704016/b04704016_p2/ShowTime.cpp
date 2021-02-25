#include <stdio.h>

#include "ShowTime.h"
#include "LTexture.h"

using namespace std;

extern LTexture gTextTexture;
extern TTF_Font *gFont;

// Constructor
// set member data hour and minute to zero and set time[5] to “00:00”
ShowTime::ShowTime(int h,int m)
{
    hour = 0;
    minute = 0;
    time[0] = '0';
    time[1] = '0';
    time[2] = ':';
    time[3] = '0';
    time[4] = '0';
}

// set hour to h and set minute to m and update time[5] as “h:m”
void ShowTime::setTime(int h,int m)
{
    time[0] = (h / 10) + '0';
    time[1] = (h % 10) + '0';
    time[3] = (m / 10) + '0';
    time[4] = (m % 10) + '0';
    string theTime;
    theTime = time;
    gTextTexture.loadFromRenderedText( theTime , { 0, 0, 0xFF } );
}


// Reference: http://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
// You only have to copy the content of loadMedia() and
// modify the font size, font color, and loadFromRenderedText()
bool ShowTime::loadMedia()
{
    bool success = true;

	//Open the font
	gFont = TTF_OpenFont( "Resource/lazy.ttf", 44 );
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 0, 0, 0xFF };
		if( !gTextTexture.loadFromRenderedText( "00:00" , textColor ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}
