
#include "corewar.h"


void 		big_hexa_2_dec(char *str, int size)
{

	print_memory(str, size, 4, 1);
	invert_bytes((void *)str, size);
	print_memory(str, size, 4, 1);
	ft_printf("El numero es: %d", *((int *)str));

	// i = str[4];
	// ft_putnbr(i);
	// while (i > 0)
	// {
	// 	ft_
	// 	i--;
	// }ma

}
