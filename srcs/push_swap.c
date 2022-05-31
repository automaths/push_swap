/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:51:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/31 02:04:57 by nsartral         ###   ########.fr       */
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

void	sort_two(t_list **bluepill)
{
	if ((*bluepill)->content > (*bluepill)->next->content)
		sa(*bluepill);
	if ((*bluepill)->content < (*bluepill)->next->content)
		return ;
}

void	sort_three(t_list **bluepill, t_struct *data)
{
	if (((*bluepill)->content > (*bluepill)->next->content) && ((*bluepill)->next->content < (*bluepill)->next->next->content) && ((*bluepill)->content < (*bluepill)->next->next->content))
	{
		sa(*bluepill);
		return ;
	}
	if (((*bluepill)->content > (*bluepill)->next->content) && ((*bluepill)->next->content > (*bluepill)->next->next->content) && ((*bluepill)->content > (*bluepill)->next->next->content))
	{
		sa(*bluepill);
		rra(bluepill, data);
		return ;
	}
	if (((*bluepill)->content > (*bluepill)->next->content) && ((*bluepill)->next->content < (*bluepill)->next->next->content) && ((*bluepill)->content > (*bluepill)->next->next->content))
	{
		ra(bluepill);
		return ;
	}
	if (((*bluepill)->content < (*bluepill)->next->content) && ((*bluepill)->next->content > (*bluepill)->next->next->content) && ((*bluepill)->content < (*bluepill)->next->next->content))
	{
		sa(*bluepill);
		ra(bluepill);
		return ;
	}
	if (((*bluepill)->content < (*bluepill)->next->content) && ((*bluepill)->next->content > (*bluepill)->next->next->content) && ((*bluepill)->content > (*bluepill)->next->next->content))
	{
		rra(bluepill, data);
		return ;
	}
}

// void	sort_four(t_list **bluepill, t_list **redpill, t_struct *data)
// {
	
// }

void	method_one(t_list *bluepill, t_struct *data)
{
	data->nb_one = 0;
	while (bluepill != NULL && bluepill->content < data->to_order)
	{
		data->nb_one++;
		bluepill = bluepill->next;
	}
}

void	apply_one(t_list **bluepill, t_list **redpill, t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->nb_one)
	{
		ra(bluepill);
		i++;
	}
	pa(bluepill, redpill);
	i = 0;
	while (i < data->nb_one)
	{
		rra(bluepill, data);
		i++;
	}
}

void	sort_five(t_list **bluepill, t_list **redpill, t_struct *data)
{
	pb(bluepill, redpill);
	pb(bluepill, redpill);
	sort_three(bluepill, data);
	data->to_order = (*redpill)->content;
	method_one(*bluepill, data);
	apply_one(bluepill, redpill, data);
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
		sort_three(bluepill, data);
	// if (ft_lstsize(*bluepill) == 4)
	// 	sort_four(bluepill, redpill, data);
	if (ft_lstsize(*bluepill) == 5)
		sort_five(bluepill, redpill, data);
}

void	solving(t_list **bluepill, t_list **redpill, t_struct *data)
{
	(void)data;
	data->is_rrr = 0;
	rank_convert(bluepill);
	if (ft_lstsize(*bluepill) > 1 && ft_lstsize(*bluepill) < 6)
	{
		sort_special(bluepill, redpill, data);
		return ;
	}
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
