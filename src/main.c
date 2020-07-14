#include "the_robots.h"

int main(int argc,char *argv[]){
	field=calloc(1,sizeof(Field));

	create_field();
	display_field();

	return 0;
}
