#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<termio.h>

typedef struct{
	enum {NONE, PLAYER, ROBOT, GARBAGE} state;
}Block;

typedef struct{
	int x;
	int y;
	bool active;
}Robot;

typedef struct{
	int size_x;
	int size_y;
	int player_x;
	int player_y;
	int robot_num;
	int robots_remain;
	int level;
	Robot *robots;
	Block **matrix;
}Field;

Field *field;

// setup.c
void create_field();
void get_field_size();
void set_robots();
int skip_block(int x,int y);

// display.c
void display_field();
void display_prompt();
void display_block(Block *block,int x,int y);
void display_gameover();
void display_gameclear();

// playgame.c
void playgame();
void get_command();
void random_set(int *x,int *y);
bool in_field(int x,int y);
void robot_collision(int x,int y);
void move_player(int next_x,int next_y);
void move_robots(int player_x,int player_y);
void next_stage();

// getChar.c
char getChar();

