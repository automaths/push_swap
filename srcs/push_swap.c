/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:51:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 23:48:31 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cover(t_list **bluepill, t_list **redpill)
{
	while (ft_lstsize(*redpill) != 0)
		pa(bluepill, redpill);
}

void	sorting(t_list **bluepill, t_list **redpill, t_struct *data)
{
	int	size;
	int	size_max;

	size_max = 0;
	while (size_max < data->size_bits)
	{
		size = data->bluepill_size;
		while (size > 0)
		{
			if (((*bluepill)->content >> size_max) & (1 == 1))
				ra(bluepill);
			else
				pb(bluepill, redpill);
			size--;
		}
		cover(bluepill, redpill);
		size_max++;
	}
}

void	solving(t_list **bluepill, t_list **redpill, t_struct *data)
{
	(void)data;
	data->is_rrr = 0;
	rank_convert(bluepill);
	data->size_bits = find_bit_max(*bluepill);
	data->bluepill_size = ft_lstsize(*bluepill);
	sorting(bluepill, redpill, data);
}

int	main(int argc, char **argv)
{
	t_list		*bluepill;
	t_list		*redpill;
	t_struct	data;

	if (argc == 1)
		return (0);
	if (argc == 2 && parsing_one(argv[1], &bluepill) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc >= 3 && parsing_two(argv, &bluepill) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	redpill = NULL;
	solving(&bluepill, &redpill, &data);
	return (0);
}
