#include "the_robots.h"

Field *field;

void display_prompt(){
	printf("[level:%d score:%d]>>",field->level,field->score);
}

void display_block(Block *block,int x,int y){
	printf("\e[42m");
	switch(block->state){
		case NONE:
			printf(" ");
			break;
		case PLAYER:
			printf("\e[31m@\e[39m");
			break;
		case ROBOT:
			printf("+");
			break;
		case GARBAGE:
			printf("\e[34m*\e[39m");
			break;
	}
	printf("\e[49m");
}

void display_field(){
	int i,j;
	int x,y;
	char c;

	//printf("\033c");
	printf("\033[1;1H");
	printf("\033[2J");


	printf("\e[40m  ");
	for(i=0;i<field->size_x;i++)
		printf(" ");
	printf("  \e[49m\n");

	for(y=0;y<field->size_y;y++){
		printf("\e[40m  \e[49m");
		for(x=0;x<field->size_x;x++){
			display_block(&(field->matrix[x][y]),x,y);
		}
		printf("\e[40m  \e[49m\n");
	}

	printf("\e[40m  ");
	for(i=0;i<field->size_x;i++)
		printf(" ");
	printf("  \e[49m\n");
}

void display_gameover(){
	printf("game over...\n");
}

void display_gameclear(){
	printf("game clear!\n");
}

