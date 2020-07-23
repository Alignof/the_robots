#include "the_robots.h"

int main(int argc,char *argv[]){
	field=calloc(1,sizeof(Field));

	create_field();
	display_field();
	play_game();

	return 0;
}
