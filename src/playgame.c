#include "the_robots.h"

bool in_field(int x,int y){
	return (0 <= y && y <= field->size_y-1) && (0 <= x && x <= field->size_x-1);
}

void move_player(int next_x,int next_y){
	if(in_field(next_x,next_y)){
		field->matrix[field->player_x][field->player_y].state=NONE;
		field->player_x=next_x;
		field->player_y=next_y;
		field->matrix[next_x][next_y].state=PLAYER;
	}
}

void get_command(){
	char command;

	do{
		display_field();
		display_prompt();
		command=getChar();

		printf("%d\n",command);
		switch(command){
			// upper
			case 8:
				move_player(field->player_x,field->player_y-1);
				break;
			// upper right
			case 9:
				move_player(field->player_x+1,field->player_y-1);
				break;
			// right
			case 6:
				move_player(field->player_x+1,field->player_y);
				break;
			// lower right
			case 3:
				move_player(field->player_x+1,field->player_y+1);
				break;
			// lower
			case 2:
				move_player(field->player_x,field->player_y+1);
				break;
			// lower left
			case 1:
				move_player(field->player_x-1,field->player_y+1);
				break;
			// left
			case 4:
				move_player(field->player_x-1,field->player_y);
				break;
			// upper left
			case 7:
				move_player(field->player_x-1,field->player_y-1);
				break;
			// does not move
			case 5:
				break;
			default:
				command=0;
		}
	}while(in_field(field->player_x,field->player_y) || command==0);
}

void playgame(){
	while(1){
		get_command();
	}
}
