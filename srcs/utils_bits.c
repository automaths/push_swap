/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:40:27 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/31 04:37:28 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_power(int nb, int power)
{
	int	x;

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
	int		max;

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
	int	max;
	int	i;

	i = 1;
	max = find_max_rank(bluepill);
	while ((to_power(2, i - 1) > max) || ((to_power(2, i) - 1) < max))
		i++;
	return (i);
}

int	find_rank(t_list *bluepill, int content)
{
	int	rank;

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
	t_list	*tmp;
	t_list	*copy;

	copy = ft_lstmap(*bluepill);
	tmp = *bluepill;
	while (tmp != NULL)
	{
		tmp->content = find_rank(copy, tmp->content);
		tmp = tmp->next;
	}
	while (copy != NULL)
	{
		tmp = copy;
		copy = (copy)->next;
		free(tmp);
	}
}
