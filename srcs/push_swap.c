#include "push_swap.h"

void	matrix_init(matrix *pills, int argc, char **argv)
{
	int i;
	
	i = 0;
	pills->sizemax = argc - 1;
	pills->sizeblue = argc - 1;
	pills->sizered = 0;
	pills->bluepill = (int *)malloc(sizeof(int) * argc);
	pills->redpill = (int *)malloc(sizeof(int) * argc);
	pills->average = 0;
	while (i < argc)
	{
		pills->bluepill[i] = ft_atoi((const char *)argv[i + 1]);
		i++;
	}
}

void	read_pills(matrix *pills)
{
	int i;
	i = 0;
	while (i < pills->sizemax)
	{
		if (i < pills->sizeblue)
			ft_printf("%d", pills->bluepill[i]);
		else 
			ft_printf(" ");
		if (i < pills->sizered)
			ft_printf(" %d\n", pills->redpill[i]);
		else
			ft_printf("  \n");
		i++;
	}
	ft_printf("- -\n");
	ft_printf("a b\n\n");
}

int 	main(int argc, char **argv)
{
	matrix pills;

	matrix_init(&pills, argc, argv);
	read_pills(&pills);
	linear_bluepill_sort(&pills);
	read_pills(&pills);
	return (0);
}