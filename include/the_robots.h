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
	int x;
	int y;
}Robot;

typedef struct{
	int size_x;
	int size_y;
	int player_x;
	int player_y;
	int robot_num;
	Robot *robots;
	Block **matrix;
}Field;

Field *field;

// setup.c
void create_field();
void get_field_size();

// display.c
void display_field();
void display_prompt();
void display_block(Block *block,int x,int y);

// playgame.c
void playgame();
void get_command();
bool in_field(int x,int y);

// getChar.c
char getChar();

