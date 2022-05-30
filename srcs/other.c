/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:45:47 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 22:13:56 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	solving(t_list **bluepill, t_list **redpill, t_struct *data)
// {
// 	spliting(bluepill, redpill);
// 	// printing(*bluepill, *redpill);
// 	// ft_printf("\n\n");
// 	data->center = ft_lstsize(*bluepill);
// 	// printing(*bluepill, *redpill);
// 	// ft_printf("\n\n");
// 	cover(bluepill, redpill);
// 	while (*redpill != NULL)
// 	{
// 		data->to_order = ft_lstcontent(*redpill, 1);
// 		method_one(*bluepill, data);
// 		method_two(*redpill, data);
// 		if (data->nb_one <= data->nb_two)
// 		{
// 			apply_one(bluepill, redpill, data);
// 			// ft_printf("\nMETHOD ONE\n");
// 		}
// 		else
// 		{
// 			apply_two(bluepill, redpill, data);
// 			// ft_printf("\nMETHOD TWO\n");
// 		}
// 		// printing(*bluepill, *redpill);
// 		// ft_printf("\n\n");
// 	}
// }

// int		find_min(t_list *pill, int start)
// {
// 	int i;
// 	int min;
// 	int index;

// 	i = 0;
// 	min = 2147483648;
// 	index = 0;
// 	while (start <= ft_lstsize(pill))
// 	{
// 		if (ft_lstcontent(pill, i) < min)
// 		{
// 			min = ft_lstcontent(pill, i);
// 			index = i;
// 		}
// 		start++;
// 	}
// 	return (index);
// }
// int 	is_sorted(t_list *pill)
// {
// 	int i; 
// 	int content;
// 	i = 1;
// 	content = ft_lstcontent(pill, i);
// 	while (i < ft_lstsize(pill) - 1)
// 	{
// 		i++;
// 		if (ft_lstcontent(pill, i) < content)
// 			return (i);
// 		content = ft_lstcontent(pill, i);
// 	}
// 	return (0);
// }
// void	sort_element(t_list **pill, int i)
// {
// 	int n;
// 	int m;
// 	int x;
// 	n = nb_r(*pill, i);
// 	m = nb_rr(*pill, i);
// 	if (n > m)
// 		x = m;
// 	else
// 		x = n;
// }
// void	linear_sort(t_list **pill)
// {
// 	int min;
// 	int x;
// 	while (is_sorted(*pill))
// 	{
// 		x = is_sorted(*pill);
// 		sort_element(pill, x);
// 	}	
// }