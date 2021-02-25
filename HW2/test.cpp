#include <iostream>
#include <vector>
#include <curses.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <ctime>

using namespace std;

struct snakepart{
	int x,y;
	snakepart(int col, int row);
	snakepart();
};

class snakeclass{


	int del;
	bool get;
	int points;
	char direction;
	int maxwidth;
	int maxheight;
	char partchar;
	char oldalchar;
	char etel;
	std::vector<snakepart> snake; //represent the snake

	void putfood();
	bool collision();
	void movesnake();

public:
	snakeclass();
	~snakeclass();
	void start();

};

snakepart::snakepart(int col,int row)
{
	x=col;
	y=row;
}

snakepart::snakepart()
{
	x=0;
	y=0;
}

snakeclass::snakeclass()
{
	initscr();
	nodelay(stdscr,true);			//if there wasn't any key pressed don't wait for keypress
	keypad(stdscr,true);			//init the keyboard
	noecho();									//don't write
	curs_set(0);							//cursor invisible
	getmaxyx(stdscr,maxheight,maxwidth);
	partchar='@';
	oldalchar='#';
	etel='*';
	for(int i=0;i<4;i++)
		snake.push_back(snakepart(4-i,1));
	points=0;
	del=300000;
	get=0;
	direction='r';
	srand(time(NULL));
	putfood();
	//make the game-board -- up-vertical
	for(int i=0;i<15;i++)
	{
		move(0,i);
		addch(oldalchar);
	}
	//left-horizontal
	for(int i=0;i<10;i++)
	{
		move(i,0);
		addch(oldalchar);
	}
	//down-vertical
	for(int i=0;i<15;i++)
	{
		move(9,i);
		addch(oldalchar);
	}
	//right-horizontal
	for(int i=0;i<10;i++)
	{
		move(i,14);
		addch(oldalchar);
	}
	//draw the snake
	for(int i=0;i<snake.size();i++)
	{
		move(snake[i].y,snake[i].x);
		addch(partchar);
	}
	refresh();
}

snakeclass::~snakeclass()
{
	nodelay(stdscr,false);
	getch();
	endwin();
}

void snakeclass::putfood()
{
	move(1,8);
	addch(etel);
	move(2,10);
	addch(etel);
	move(3,12);
	addch(etel);
	move(4,1);
	addch(etel);
	move(4,8);
	addch(etel);
	move(5,13);
	addch(etel);
	move(6,2);
	addch(etel);
	move(6,6);
	addch(etel);
	move(8,10);
	addch(etel);
	move(7,12);
	addch(etel);

    refresh();
}

bool snakeclass::collision()
{
	static bool food_1 = true, food_2 = true, food_3 = true, food_4 = true, food_5 = true;
    static bool food_6 = true, food_7 = true, food_8 = true, food_9 = true, food_10 = true;

	if(snake[0].x==0 || snake[0].x==14 || snake[0].y==0 || snake[0].y==9)
		return true;
	for(int i=2;i<snake.size();i++)
	{
		if(snake[0].x==snake[i].x && snake[0].y==snake[i].y)
			return true;
	}
	//collision with the food
	if((snake[0].x==8 && snake[0].y==1) && food_1 )
	{
		get=true;
		food_1 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==10 && snake[0].y==2) && food_2)
	{
		get=true;
		food_2 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==12 && snake[0].y==3) && food_3)
	{
		get=true;
		food_3 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==1 && snake[0].y==4) && food_4)
	{
		get=true;
		food_4 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==8 && snake[0].y==4) && food_5)
	{
		get=true;
		food_5 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==13 && snake[0].y==5) && food_6)
	{
		get=true;
		food_6 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==2 && snake[0].y==6) && food_7)
	{
		get=true;
		food_7 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==6 && snake[0].y==6) && food_8)
	{
		get=true;
		food_8 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==10 && snake[0].y==8) && food_9)
	{
		get=true;
		food_9 = false;
		points+=10;
	}else get=false;

	if((snake[0].x==12 && snake[0].y==7) && food_10)
	{
		get=true;
		food_10 = false;
		points+=10;
	}else get=false;

	return false;
}


void snakeclass::movesnake()
{
	//detect key
	int tmp=getch();
	switch(tmp)
	{
		case KEY_LEFT:
			if(direction!='r')
				direction='l';
			break;
		case KEY_UP:
			if(direction!='d')
				direction='u';
			break;
		case KEY_DOWN:
			if(direction!='u')
				direction='d';
			break;
		case KEY_RIGHT:
			if(direction!='l')
				direction='r';
			break;
		case KEY_BACKSPACE:
			direction='q';
			break;
	}
	//if there wasn't a collision with food
	if(!get)
	{
		move(snake[snake.size()-1].y,snake[snake.size()-1].x);
		printw(" ");
		refresh();
		snake.pop_back();
	}
	if(direction=='l')
	{
		snake.insert(snake.begin(),snakepart(snake[0].x-1,snake[0].y));
	}else if(direction=='r'){
		snake.insert(snake.begin(),snakepart(snake[0].x+1,snake[0].y));

	}else if(direction=='u'){
		snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y-1));
	}else if(direction=='d'){
		snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y+1));
	}
		move(snake[0].y,snake[0].x);
		addch(partchar);
	refresh();
}

void snakeclass::start()
{
	while(1)
	{
		if(points >= 100)
        {
            move(15,0);
            printw("You win!!!");
			break;
        }
		if(collision())
		{
			move(15,0);
			printw("Dead\nYou get %d points",points);
			break;
		}
		movesnake();
		if(direction=='q')				//exit
			break;
		usleep(del);			//Linux delay
	}
}

int main()
{
	snakeclass s;
	s.start();
	return 0;
}
