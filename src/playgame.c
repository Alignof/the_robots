#include "the_robots.h"

void play_game(){
	char command;

	while(1){
		command=getChar();
		switch(command){
			case 0:
				if(0 < field->player_x)
					(field->player_x)--;
				break;
			case 1:
				if(field->player_y < field->size_y-1)
					(field->player_y)++;
				break;
			case 2:
				if(0 < field->player_y)
					(field->player_y)--;
				break;
			case 3:
				if(field->player_x < field->size_x-1)
					(field->player_x)++;
				break;
		}
	}
}

