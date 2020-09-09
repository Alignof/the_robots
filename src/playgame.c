#include "the_robots.h"

Field *field;
bool is_gameover;
bool is_gameclear;

bool in_field(int x,int y){
	return (0 <= y && y < field->size_y) && (0 <= x && x < field->size_x);
}

void robot_collision(int x,int y){
	field->matrix[x][y].state=GARBAGE;
	for(int i=0;i<field->robot_num;i++){
		if(field->robots[i].x==x && field->robots[i].y==y){
			field->robots[i].active=false;
			field->robots_remain--;
			field->score++;
		}
	}
}

void move_robots(int player_x,int player_y){
	int *x;
	int *y;
	int *remain=&(field->robots_remain);

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
				(*remain)--;
				field->score++;
			}else if(field->matrix[*x][*y].state==ROBOT){
				robot_collision(*x,*y);
			}else if(field->matrix[*x][*y].state==PLAYER){
				is_gameover=true;
			}
		}
	}

	if(field->robots_remain==0) next_stage();
}

void move_player(int next_x,int next_y){
	if(in_field(next_x,next_y)){
		field->matrix[field->player_x][field->player_y].state=NONE;
		field->player_x=next_x;
		field->player_y=next_y;

		if(field->matrix[next_x][next_y].state == ROBOT){
			is_gameover=true;
		}else{
			field->matrix[next_x][next_y].state=PLAYER;
			move_robots(field->player_x,field->player_y);
		}
	}
}


void next_stage(){
	int rx,ry;

	field->score+=(field->level)*10;
	field->level++;
	if(field->level<10) field->robot_num+=5;
	field->robots_remain=field->robot_num;

	for(int i=0;i<field->robot_num;i++){
		field->robots[i].active=true;
		rx=field->robots[i].x;
		ry=field->robots[i].y;
		field->matrix[rx][ry].state=NONE;
	}

	random_set(&(field->player_x),&(field->player_y));
	set_robots();
}

void random_set(int *x,int *y){
	int rx,ry;

	field->matrix[*x][*y].state=NONE;
	do{
		*x=rand()%(field->size_x);
		*y=rand()%(field->size_y);
	}while(field->matrix[*x][*y].state==ROBOT || field->matrix[*x][*y].state==GARBAGE);
	field->matrix[*x][*y].state=PLAYER;

}

void no_more_movement(int player_x,int player_y){
	int *x;
	int *y;
	int *remain=&(field->robots_remain);

	while(field->robots_remain!=0){
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
					(*remain)--;
					field->score+=2;
				}else if(field->matrix[*x][*y].state==ROBOT){
					robot_collision(*x,*y);
					field->score++;
				}else if(field->matrix[*x][*y].state==PLAYER){
					is_gameover=true;
					return;
				}
			}
		}
	}

	next_stage();
}

void get_command(){
	char command;

	while(!(is_gameover || is_gameclear)){
		display_field();
		display_prompt();

		do{
			command=getChar();
		}while(!(('0'<=command && command<='9') || command=='+'));


		if(command=='0'){
			random_set(&(field->player_x),&(field->player_y));
			move_robots(field->player_x,field->player_y);
		}else if(command=='+'){
			printf("\nWon't you move anymore?[y/n]>>>");
			command=getChar();
			if(command=='y') no_more_movement(field->player_x,field->player_y);
		}else{
			command-='0';
			move_player((field->player_x)+((command-1)%3-1),(field->player_y)-((command-1)/3-1));
		}
	}

	if(is_gameclear) display_gameclear();
	if(is_gameover) display_gameover();
}


void playgame(){
	get_command();
}
