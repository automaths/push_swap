/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:45:47 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 23:52:55 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printing(t_list *bluepill, t_list *redpill)
{
	t_list	*tmp_blue;
	t_list	*tmp_red;

	tmp_blue = bluepill;
	tmp_red = redpill;
	while (bluepill != NULL || redpill != NULL)
	{
		if (bluepill != NULL && redpill != NULL)
		{
			ft_printf("%d //  %d\n", bluepill->content, redpill->content);
			bluepill = bluepill->next;
			redpill = redpill->next;
		}
		if (bluepill != NULL && redpill == NULL)
		{
			ft_printf("%d\n", bluepill->content);
			bluepill = bluepill->next;
		}
		if (redpill != NULL && bluepill == NULL)
		{
			ft_printf("  //  %d\n", redpill->content);
			redpill = redpill->next;
		}
	}
	ft_printf ("- -\na b");
	bluepill = tmp_blue;
	redpill = tmp_red;
}

// int	median_search(t_list *bluepill, int x)
// {
// 	int	n;
// 	int	m;
// 	int	i;

// 	n = 0;
// 	m = 0;
// 	while (bluepill != NULL)
// 	{
// 		if (bluepill->content >= x)
// 			n++;
// 		if (bluepill->content < x)
// 			m++;
// 		bluepill = bluepill->next;
// 	}
// 	if (n > 0)
// 		n--;
// 	if (n >= m)
// 		i = n - m;
// 	else
// 		i = m - n;
// 	return (i);
// }

// int	is_median(t_list *bluepill)
// {
// 	int	i;
// 	int	median;
// 	int	max;

// 	i = 1;
// 	max = 2000;
// 	median = 0;
// 	while (i <= ft_lstsize(bluepill))
// 	{
// 		if (median_search(bluepill, ft_lstcontent(bluepill, i)) < max)
// 		{
// 			max = median_search(bluepill, ft_lstcontent(bluepill, i));
// 			median = i;
// 		}
// 		i++;
// 	}
// 	return (median);
// }

// void	spliting(t_list **bluepill, t_list **redpill)
// {
// 	int	median;
// 	int	size;
// 	int	i;

// 	i = 0;
// 	if (is_median(*bluepill) == 0)
// 		return ;
// 	median = ft_lstcontent(*bluepill, is_median(*bluepill));
// 	size = ft_lstsize(*bluepill);
// 	while (i < size)
// 	{
// 		if ((*bluepill)->content < median)
// 			pb(bluepill, redpill);
// 		else
// 			ra(bluepill);
// 		i++;
// 	}
// }

// void	method_one(t_list *bluepill, t_struct *data)
// {
// 	data->nb_one = 0;
// 	while (bluepill != NULL && bluepill->content < data->to_order)
// 	{
// 		data->nb_one++;
// 		bluepill = bluepill->next;
// 	}
// 	data->nb_one++;
// }

// void	method_two(t_list *redpill, t_struct *data)
// {
// 	int	max;
// 	int	n;

// 	max = -2147483648;
// 	data->nb_two = 0;
// 	n = 1;
// 	while (redpill != NULL && n < data->center)
// 	{
// 		if (redpill->content > max)
// 		{
// 			max = redpill->content;
// 			data->nb_two = n;
// 		}
// 		redpill = redpill->next;
// 		n++;
// 	}
// 	if (n < data->center || n == 1)
// 		data->nb_two = 2147483647;
// }

// void	apply_one(t_list **bluepill, t_list **redpill, t_struct *data)
// {
// 	int	i;

// 	i = 1;
// 	while (i < data->nb_one)
// 	{
// 		ra(bluepill);
// 		i++;
// 	}
// 	pa(bluepill, redpill);
// 	i = 1;
// 	while (i < data->nb_one)
// 	{
// 		rra(bluepill, data);
// 		i++;
// 	}
// }

// void	apply_two(t_list **bluepill, t_list **redpill, t_struct *data)
// {
// 	int	i;

// 	i = 1;
// 	while (i < data->nb_two)
// 	{
// 		rb(redpill);
// 		i++;
// 	}
// 	data->to_order = ft_lstcontent(*redpill, 1);
// 	method_one(*bluepill, data);
// 	apply_one(bluepill, redpill, data);
// 	i = 1;
// 	while (i < data->nb_two)
// 	{
// 		rrb(redpill, data);
// 		i++;
// 	}
// }

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