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
	field->robots=calloc(field->robot_num+10,sizeof(Robot));
	field->robots_remain=field->robot_num;
	field->level=1;
	for(int i=0;i<field->robot_num;i++) field->robots[i].active=true;
}

int skip_block(int x,int y){
	int out_x,out_y;
	int skip=0;

	out_x=field->size_x - x;
	out_y=field->size_y - y;
	out_x=out_x<=2 ? out_x : 0;
	out_y=out_y<=2 ? out_y : 0;


	skip=25-((5-out_x)*(5-out_y));
	return skip;
}

void set_robots(){
	int set;
	int x,y;
	int counter=0;

	while(counter < field->robot_num){
		set=rand()%((field->size_x * field->size_y)-skip_block(field->player_x,field->player_y));
		x=set%field->size_x;
		y=set/field->size_x;

		if(abs(field->player_x-x)<=2 && abs(field->player_y-y)<=2){
			set+=(field->player_y-y+2)*3;
			x=set/field->size_x;
			y=set%field->size_x;
		}

		if(field->matrix[x][y].state==NONE){
			field->matrix[x][y].state=ROBOT;
			field->robots[counter].x=x;
			field->robots[counter].y=y;
			counter++;
		}
	}
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
	set_robots();
}

