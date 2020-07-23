#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<termio.h>
#include<curses.h>

typedef struct{
	enum {NONE, PLAYER, ROBOT} state;
}Block;

typedef struct{
	int size_x;
	int size_y;
	int player_x;
	int player_y;
	int robot_num;
	Block **matrix;
}Field;

Field *field;

// setup.c
void create_field();
void get_field_size();

// display.c
void display_field();
void display_block(Block *block,int x,int y);

// play_game.c
void play_game();

// getChar.c
char getChar();

