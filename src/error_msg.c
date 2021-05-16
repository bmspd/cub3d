#include "../includes/cub3d.h"

void 	invalid_data_error(int type)
{
	if (type == 0)
		printf("!Error!\n NULL TYPE");
	if (type == 1)
		printf("!Error!\nSome error occurred with arguments inputted!!!\n");
	if (type == 2)
		printf("!Error!\nMalloc error happened!!!\n");
	if (type == 3)
		printf("!Error!\nInvalid data in .cub file!!!\n");
	exit(1);
}
