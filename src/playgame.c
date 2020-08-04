#include "the_robots.h"

bool in_field(int x,int y){
	return (0 <= y && y < field->size_y) && (0 <= x && x < field->size_x);
}

void robot_collision(int x,int y){
	field->matrix[x][y].state=GARBAGE;
	for(int i=0;i<field->robot_num;i++)
		if(field->robots[i].x==x && field->robots[i].y==y)
			field->robots[i].active=false;
}

void move_robots(int player_x,int player_y){
	int *x;
	int *y;

	for(int i=0;i<field->robot_num;i++){
		if(field->robots[i].active){
			x=&(field->robots[i].x);
			y=&(field->robots[i].y);
			field->matrix[*x][*y].state=NONE;

			if(*x<player_x) (*x)++;
			if(*x>player_x) (*x)--;
			if(*y<player_y) (*y)++;
			if(*y>player_y) (*y)--;

			if(field->matrix[*x][*y].state==NONE){
				field->matrix[*x][*y].state=ROBOT;
			}else if(field->matrix[*x][*y].state==GARBAGE){
				field->robots[i].active=false;
			}else if(field->matrix[*x][*y].state==ROBOT){
				robot_collision(*x,*y);
			}else{
				display_gameover();
			}
		}
	}
}

void move_player(int next_x,int next_y){
	if(in_field(next_x,next_y)){
		field->matrix[field->player_x][field->player_y].state=NONE;
		field->player_x=next_x;
		field->player_y=next_y;
		field->matrix[next_x][next_y].state=PLAYER;

		move_robots(field->player_x,field->player_y);
	}
}

void random_set(int *x,int *y){
	int rx,ry;

	/*
	for(int i=0;i<field->robot_num;i++){
		rx=field->robots[i].x;
		ry=field->robots[i].y;
		field->matrix[rx][ry].state=NONE;
	}
	*/

	field->matrix[*x][*y].state=NONE;
	*x=rand()%(field->size_x);
	*y=rand()%(field->size_y);
	field->matrix[*x][*y].state=PLAYER;

	//set_robots();
}

void get_command(){
	char command;

	while(1){
		display_field();
		display_prompt();

		do{
			command=getChar();
		}while(!(0<=command && command<=9) || command==5);


		if(command==0)
			random_set(&(field->player_x),&(field->player_y));
		else
			move_player((field->player_x)+((command-1)%3-1),(field->player_y)-((command-1)/3-1));
	}
}

void playgame(){
	get_command();
}
