/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:52:01 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 03:11:53 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	method_one(t_list *bluepill, t_struct *data)
{
	data->nb_one = 0;
	while (bluepill != NULL && bluepill->content < data->to_order)
	{
		data->nb_one++;
		bluepill = bluepill->next;
	}
	data->nb_one++;
}

void	method_two(t_list *redpill, t_struct *data)
{
	int	max;
	int	n;

	max = -2147483648;
	data->nb_two = 0;
	n = 1;
	while (redpill != NULL && n < data->center)
	{
		if (redpill->content > max)
		{
			max = redpill->content;
			data->nb_two = n;
		}
		redpill = redpill->next;
		n++;
	}
	if (n < data->center || n == 1)
		data->nb_two = 2147483647;
}

void	apply_one(t_list **bluepill, t_list **redpill, t_struct *data)
{
	int	i;

	i = 1;
	while (i < data->nb_one)
	{
		ra(bluepill);
		i++;
	}
	pa(bluepill, redpill);
	i = 1;
	while (i < data->nb_one)
	{
		rra(bluepill, data);
		i++;
	}
}

void	apply_two(t_list **bluepill, t_list **redpill, t_struct *data)
{
	int	i;

	i = 1;
	while (i < data->nb_two)
	{
		rb(redpill);
		i++;
	}
	data->to_order = ft_lstcontent(*redpill, 1);
	method_one(*bluepill, data);
	apply_one(bluepill, redpill, data);
	i = 1;
	while (i < data->nb_two)
	{
		rrb(redpill, data);
		i++;
	}
}
