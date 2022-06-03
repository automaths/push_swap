/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:59:25 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/31 05:58:12 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min(t_list **bluepill, t_list **redpill, t_struct *data)
{
	int		min;
	t_list	*tmp;

	tmp = *bluepill;
	min = 2147483647;
	while (tmp != NULL)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	tmp = *bluepill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->content == min)
	{
		rra(bluepill, data);
		if (pb(bluepill, redpill) == 0)
			return ;
		return ;
	}
	while ((*bluepill)->content != min)
		ra(bluepill);
	if (pb(bluepill, redpill) == 0)
		return ;
}

void	sort_five(t_list **bluepill, t_list **redpill, t_struct *data)
{
	sort_min(bluepill, redpill, data);
	sort_min(bluepill, redpill, data);
	sort_three_one(bluepill, data);
	sort_three_two(bluepill, data);
	if (pa(bluepill, redpill) == 0)
		return ;
	if (pa(bluepill, redpill) == 0)
		return ;
}

void	sort_four(t_list **bluepill, t_list **redpill, t_struct *data)
{
	if (pb(bluepill, redpill) == 0)
		return ;
	sort_three_one(bluepill, data);
	sort_three_two(bluepill, data);
	data->to_order = (*redpill)->content;
	method_one(*bluepill, data);
	apply_one(bluepill, redpill, data);
}

void	sort_special(t_list **bluepill, t_list **redpill, t_struct *data)
{
	(void)redpill;
	(void)data;
	if (ft_lstsize(*bluepill) == 2)
		sort_two(bluepill);
	if (ft_lstsize(*bluepill) == 3)
	{
		sort_three_one(bluepill, data);
		sort_three_two(bluepill, data);
	}
	if (ft_lstsize(*bluepill) == 4)
		sort_four(bluepill, redpill, data);
	if (ft_lstsize(*bluepill) == 5)
		sort_five(bluepill, redpill, data);
}
