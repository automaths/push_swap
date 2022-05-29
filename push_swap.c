#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

//

int 	main(int argc, char **argv)
{
	int *split;
	int i;
	
	i = 0;
	split = (int *)malloc(sizeof(int) * argc);
	while (i < argc)
	{
		split[i] = ft_atoi((const char *)argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", split[i]);
		i++;
	}
	ft_printf("-\n");
	ft_printf("a");
	return (0);
}