#include "push_swap.h"

void	split_average(matrix *pills)
{
	int i;
	
	i = 0;
	while (i < pills->sizeblue)
	{
		pills->average += pills->bluepill[i];
		i++;
	}
	pills->average /= pills->sizeblue;
	ft_printf("the average is %d\n\n", pills->average);
}

void	split_sort(matrix *pills)
{
	int i;
	
	split_average(pills);
	i = 0;
	while (i < pills->sizeblue)
	{
		if (pills->bluepill[0] < pills->average)
			move_pb(pills);
		if (pills->bluepill[0] >= pills->average)
			move_ra(pills);
		i++;
	}
}

int	check_bluepill_sort(matrix *pills)
{
	int i;
	int t;
	
	i = 1;
	t = 0;
	while (i < pills->sizeblue)
	{
		if (pills->bluepill[i] < pills->bluepill[i - 1])
			t++;
		i++;
	}
	if (t == 1)
		return (1);
	if (t == 0)
		return (0);
	return (-1);
}

int	check_last_bluepill_sort(matrix *pills)
{
	int i;
		
	i = 1;
	while (i < pills->sizeblue)
	{
		if (pills->bluepill[i] < pills->bluepill[i - 1])
			return(i);
		i++;
	}
	return (0);
}

void	linear_bluepill_sort(matrix *pills)
{
	// int t;
	while (check_bluepill_sort(pills) == -1)
	{
		if (pills->bluepill[1] < pills->bluepill[0])
		{
			if(pills->bluepill[0] > pills->bluepill[pills->sizeblue - 1])
				move_ra(pills);
			else
				move_sa(pills);
		}
		else
			move_ra(pills);
		read_pills(pills);
	}
	ft_printf("HEYHEY");
	read_pills(pills);
	// t = check_last_bluepill_sort(pills);
	// if (t > 0)
	// {
	// 	while (t > 1)
	// 	{
	// 		move_ra(pills);
	// 		t--;
	// 	}
	// 	move_sa(pills);
	// 	while (t < pills->sizeblue - 1)
	// 	{
	// 		move_ra(pills);
	// 		t++;
	// 	}
	// }
	// ft_printf("the end is here \n");
	// read_pills(pills);
}
