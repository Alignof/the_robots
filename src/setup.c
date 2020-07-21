#include "the_robots.h"

void get_field_size(){
	char level;
	do{
		printf("input field size[S:12*48 M:20*80 L:30*120]>>");
		scanf("%c",&level);

		switch(level){
			case 's':
			case 'S':
				field->size_y=12;
				field->robot_num=5;
				break;
			case 'm':
			case 'M':
				field->size_y=20;
				field->robot_num=8;
				break;
			case 'l':
			case 'L':
				field->size_y=30;
				field->robot_num=12;
				break;
			default:
				field->size_y=0;
		}
	}while(field->size_y==0);
	field->size_x=(field->size_y)*4;
}

void set_robot(){
	int x,y;
	int counter=0;

	srand((unsigned)time(NULL));

/*
	while(counter < field->robot_num){
		set=rand()%((field->size_x * field->player_y)-16);

	}
*/
}

void create_field(){
	int x,y;

	get_field_size();
	field->matrix=(Block **)calloc(field->size_x,sizeof(Block *));
	
	for(int i=0;i<field->size_x;i++)
		field->matrix[i]=(Block *)calloc(field->size_y,sizeof(Block));


	x=rand()%(field->size_x);
	y=rand()%(field->size_y);

	field->player_x=x;
	field->player_y=y;
	field->matrix[x][y].state=PLAYER;
}
