#include "the_robots.h"

bool in_field(int x,int y){
	return (0 < y && y < field->size_y-1) && (0 < x && x < field->size_x-1);
}

void move_player(int now_x,int now_y,int next_x,int next_y){
	if((0 < field->player_y && field->player_y < field->size_y-1) && (0 < field->player_x && field->player_x < field->size_x-1))
}

void get_command(){
	char command;

	do{
		display_field();
		command=getChar();

		switch(command){
			// left
			case 4:
				break;
			// up
			case 8:
				break;
			// down
			case 6:
				break;
			// down
			case 2:
				break;
			default:
				command=0;
		}
	}while(in_field(field->player_x,field->player_y) || command==0);
}
