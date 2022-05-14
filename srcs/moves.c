#include "push_swap.h"

void	move_sa(matrix *pills)
{
	int tmp;
	if (pills->sizeblue > 1)
	{
		tmp = pills->bluepill[0];
		pills->bluepill[0] = pills->bluepill[1];
		pills->bluepill[1] = tmp;
	}
}

void	move_sb(matrix *pills)
{
	int tmp;
	if (pills->sizered > 1)
	{
		tmp = pills->redpill[0];
		pills->redpill[0] = pills->redpill[1];
		pills->redpill[1] = tmp;
	}
}

void	move_ss(matrix *pills)
{
	int tmp;
	if (pills->sizeblue > 1)
	{
		tmp = pills->bluepill[0];
		pills->bluepill[0] = pills->bluepill[1];
		pills->bluepill[1] = tmp;
	}
	if (pills->sizered > 1)
	{
		tmp = pills->redpill[0];
		pills->redpill[0] = pills->redpill[1];
		pills->redpill[1] = tmp;
	}
}

void	move_pa(matrix *pills)
{
	int i;
	if (pills->sizered == 0)
		return ;
	i = pills->sizeblue + 1;
	pills->sizeblue++;
	while (i > 0)
	{
		pills->bluepill[i] = pills->bluepill[i - 1];
		i--;
	}
	pills->bluepill[i] = pills->redpill[i];
	while (i < pills->sizered - 1)
	{
		pills->redpill[i] = pills->redpill[i + 1];
		i++;
	}
	pills->redpill[i] = 0;
	pills->sizered--;
}

void	move_pb(matrix *pills)
{
	int i;
	if (pills->sizeblue == 0)
		return ;
	i = pills->sizered + 1;
	pills->sizered++;
	while (i > 0)
	{
		pills->redpill[i] = pills->redpill[i - 1];
		i--;
	}
	pills->redpill[i] = pills->bluepill[i];
	while (i < pills->sizeblue - 1)
	{
		pills->bluepill[i] = pills->bluepill[i + 1];
		i++;
	}
	pills->bluepill[i] = 0;
	pills->sizeblue--;
}

void	move_ra(matrix *pills)
{
	int tmp;
	int i;
	i = 0;
	tmp = pills->bluepill[0];
	while (i < pills->sizeblue - 1)
	{
		pills->bluepill[i] = pills->bluepill[i + 1];
		i++;
	}
	pills->bluepill[i]= tmp;
}

void	move_rb(matrix *pills)
{
	int tmp;
	int i;
	i = 0;
	tmp = pills->redpill[0];
	while (i < pills->sizered - 1)
	{
		pills->redpill[i] = pills->redpill[i + 1];
		i++;
	}
	pills->redpill[i]= tmp;
}

void	move_rr(matrix *pills)
{
	int tmp;
	int i;
	i = 0;
	tmp = pills->bluepill[0];
	while (i < pills->sizeblue - 1)
	{
		pills->bluepill[i] = pills->bluepill[i + 1];
		i++;
	}
	pills->bluepill[i]= tmp;
	i = 0;
	tmp = pills->redpill[0];
	while (i < pills->sizered - 1)
	{
		pills->redpill[i] = pills->redpill[i + 1];
		i++;
	}
	pills->redpill[i]= tmp;
}

void	move_rra(matrix *pills)
{
	int tmp;
	int i;
	i = 0;
	tmp = pills->bluepill[pills->sizeblue - 1];
	i = pills->sizeblue - 1;
	while (i > 0)
	{
		pills->bluepill[i] = pills->bluepill[i - 1];
		i--;
	}
	pills->bluepill[0]= tmp;
}

void	move_rrb(matrix *pills)
{
	int tmp;
	int i;
	i = 0;
	tmp = pills->redpill[pills->sizered - 1];
	i = pills->sizered - 1;
	while (i > 0)
	{
		pills->redpill[i] = pills->redpill[i - 1];
		i--;
	}
	pills->redpill[0]= tmp;
}

void	move_rrr(matrix *pills)
{
	int tmp;
	int i;
	i = 0;
	tmp = pills->bluepill[pills->sizeblue - 1];
	i = pills->sizeblue - 1;
	while (i > 0)
	{
		pills->bluepill[i] = pills->bluepill[i - 1];
		i--;
	}
	pills->bluepill[0]= tmp;
	i = 0;
	tmp = pills->redpill[pills->sizered - 1];
	i = pills->sizered - 1;
	while (i > 0)
	{
		pills->redpill[i] = pills->redpill[i - 1];
		i--;
	}
	pills->redpill[0]= tmp;
}













