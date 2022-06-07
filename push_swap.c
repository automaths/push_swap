/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:51:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 08:48:59 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cover(t_list **bluepill, t_list **redpill)
{
	int	check;

	check = 1;
	while (ft_lstsize(*redpill) != 0)
	{
		check = pa(bluepill, redpill);
		if (check == 0)
			return (0);
	}
	return (1);
}

int	sorting(t_list **bluepill, t_list **redpill, t_struct *data)
{
	int	size;
	int	size_max;

	size_max = -1;
	while (++size_max < data->size_bits)
	{
		size = data->bluepill_size;
		while (size > 0)
		{
			if (((*bluepill)->content >> size_max) & (1 == 1))
			{
				if (ra(bluepill) == 0)
					return (0);
			}
			else
			{
				if (pb(bluepill, redpill) == 0)
					return (0);
			}
			size--;
		}
		if (cover(bluepill, redpill) == 0)
			return (0);
	}
	return (1);
}

int	solving(t_list **bluepill, t_list **redpill, t_struct *data)
{
	data->is_rrr = 0;
	rank_convert(bluepill);
	if (ft_lstsize(*bluepill) > 1 && ft_lstsize(*bluepill) < 6)
	{
		sort_special(bluepill, redpill, data);
		return (1);
	}
	data->size_bits = find_bit_max(*bluepill);
	data->bluepill_size = ft_lstsize(*bluepill);
	if (sorting(bluepill, redpill, data) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*bluepill;
	t_list		*redpill;
	t_struct	data;

	redpill = NULL;
	if (argc == 1)
		return (0);
	if ((argc == 2 && check_str_arg(argv[1]) == 0)
		|| (argc == 2 && check_sign_one(argv[1]) == 0)
		|| (argc >= 3 && check_sign_two(argv) == 0))
	{
		ft_printf("Error\n");
		return (0);
	}
	if ((argc == 2 && parsing_one(argv[1], &bluepill) == 0)
		|| (argc >= 3 && (parsing_two(argv, &bluepill) == 0
				|| check_argv(argc, argv) == 0)))
	{
		ft_printf("Error\n");
		return (freeing(&bluepill, &redpill), 0);
	}
	if (is_sorted(bluepill) || ft_lstsize(bluepill) == 1)
		return (freeing(&bluepill, &redpill), 0);
	solving(&bluepill, &redpill, &data);
	return (freeing(&bluepill, &redpill), 0);
}
