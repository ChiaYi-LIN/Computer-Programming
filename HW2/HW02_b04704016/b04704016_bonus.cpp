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

int del = 300000;
bool get = 0;
int points = 0;
char direction = 'r';
int maxwidth;
int maxheight;
char partchar='@';
char oldalchar='#';
char etel='*';
int length=4;
std::vector<snakepart> snake;
bool collision();
void movesnake();
void init();
void getLonger();

int main(){

    init();
    //=====build map=====
    // '#':wall
	for(int i=0;i<15;i++)
	{
		move(0,i);
		addch(oldalchar);
	}
	for(int i=0;i<10;i++)
	{
		move(i,0);
		addch(oldalchar);
	}
	for(int i=0;i<15;i++)
	{
		move(9,i);
		addch(oldalchar);
	}
	for(int i=0;i<10;i++)
	{
		move(i,14);
		addch(oldalchar);
	}
    // '*':food(egg)
    // ' ':nothing
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
    //=====init snake=====
    // store in snakeArray
    // update in map
    // '@' snake body
    for(int i=0;i<4;i++)
		snake.push_back(snakepart(4-i,1));
    for(int i=0;i<snake.size();i++)
	{
		move(snake[i].y,snake[i].x);
		addch(partchar);
	}
	refresh();
    do{
    //=====draw=====
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
		if(direction=='q')
			break;
        //=====get key=====
        //=====update direction=====
        movesnake();
        //=====check event=====
        // switch goPos
        // '*' eat and length+1, head moves on while tail remains
        // ' ' normal walk, head&tail moves on
        // '@''#' dead
        collision();
        refresh();
        usleep(del);
        //=====draw=====
    }while(1);
    nodelay(stdscr,false);
	getch();
	endwin();
	if(points >= 100)
    {
        printf("You win!!!\n");
    }
    if(points < 100)
    {
        printf("Dead\nYou get %d points\n",points);
    }
    return 0;
}

void init()
{
    initscr();
	nodelay(stdscr,true);
	keypad(stdscr,true);
	noecho();
	curs_set(0);
    getmaxyx(stdscr,maxheight,maxwidth);
    srand(time(NULL));
}

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

bool collision()
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
	if((snake[0].x==8 && snake[0].y==1) && food_1 )
	{
		food_1 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==10 && snake[0].y==2) && food_2)
	{
		food_2 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==12 && snake[0].y==3) && food_3)
	{
		food_3 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==1 && snake[0].y==4) && food_4)
	{
		food_4 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==8 && snake[0].y==4) && food_5)
	{
		food_5 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==13 && snake[0].y==5) && food_6)
	{
		food_6 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==2 && snake[0].y==6) && food_7)
	{
		food_7 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==6 && snake[0].y==6) && food_8)
	{
		food_8 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==10 && snake[0].y==8) && food_9)
	{
		food_9 = false;
		getLonger();
	}else get=false;

	if((snake[0].x==12 && snake[0].y==7) && food_10)
	{
		food_10 = false;
		getLonger();
	}else get=false;

	return false;
}

void movesnake()
{
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
	if(!get)
	{
		move(snake[snake.size()-1].y,snake[snake.size()-1].x);
		printw(" ");
		for(int i=0;i<15;i++)
        {
            move(0,i);
            addch(oldalchar);
        }
        for(int i=0;i<10;i++)
        {
            move(i,0);
            addch(oldalchar);
        }
        for(int i=0;i<15;i++)
        {
            move(9,i);
            addch(oldalchar);
        }
        for(int i=0;i<10;i++)
        {
            move(i,14);
            addch(oldalchar);
        }
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

void getLonger()
{
    get=true;
    points+=10;
    length+=1;
    snake.push_back(snakepart(2*snake[length-2].x-snake[length-3].x,2*snake[length-2].y-snake[length-3].y));
    move(snake[length-1].y,snake[length-1].x);
    addch(partchar);
}
