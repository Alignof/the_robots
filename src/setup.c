#include "the_robots.h"

void get_field_size(){
	char level;
	do{
		printf("input field size[S:5*5 M:8*8 L:12*12]>>");
		scanf("%c",&level);

		switch(level){
			case 's':
			case 'S':
				field->size_y=10;
				break;
			case 'm':
			case 'M':
				field->size_y=20;
				break;
			case 'l':
			case 'L':
				field->size_y=30;
				break;
			default:
				field->size_y=0;
		}
	}while(field->size_y==0);
	field->size_x=(field->size_y)*4;
}

void create_field(){
	int x,y;

	get_field_size();
	field->matrix=(Block **)calloc(field->size_x,sizeof(Block *));
	
	for(int i=0;i<field->size_x;i++)
		field->matrix[i]=(Block *)calloc(field->size_y,sizeof(Block));


	x=rand()%(field->size_x);
	y=rand()%(field->size_y);
	field->matrix[x][y].state=PLAYER;
}
