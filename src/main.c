#include "the_robots.h"

int main(int argc,char *argv[]){
	srand((unsigned)time(NULL));
	field=calloc(1,sizeof(Field));

	create_field();
	display_field();
	playgame();

	return 0;
}
