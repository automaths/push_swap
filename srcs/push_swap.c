/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:51:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 22:13:52 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     to_power(int nb, int power)
{
    int     x;

    if (power == 0)
        return (1);
    x = 1;
    while (power >= 1)
    {
        x *= nb;
        power--;
    }
    return (x);
}

int	find_max_rank(t_list *bluepill)
{
	int max;
	
	max = 0;
	while (bluepill != NULL)
	{
		if (bluepill->content > max)
			max = bluepill->content;
		bluepill = bluepill->next;
	}
	return (max);
}

int	find_bit_max(t_list *bluepill)
{
	int max;
	int i;
	
	i = 1;
	max = find_max_rank(bluepill);
	while ((to_power(2, i - 1) > max) || ((to_power(2, i) - 1) < max))
		i++;
	return (i);
}

int		find_rank(t_list *bluepill, int content)
{
	int rank;
	
	rank = 1;
	while (bluepill != NULL)
	{
		if (bluepill->content < content)
			rank++;
		bluepill = bluepill->next;
	}
	return (rank);
}

void	rank_convert(t_list **bluepill)
{
	t_list *tmp;
	
	tmp = *bluepill;
	while (tmp != NULL)
	{
		tmp->content = find_rank(*bluepill, tmp->content);
		tmp = tmp->next;
	}
}

void	solving(t_list **bluepill, t_list **redpill, t_struct *data)
{
	(void)data;
	data->is_rrr = 0;
	rank_convert(bluepill);
	printing(*bluepill, *redpill);
	ft_printf("\n\n");
	data->size_bits = find_bit_max(*bluepill);
	ft_printf("\nthe bit max is: %d\n", data->size_bits);
	
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
