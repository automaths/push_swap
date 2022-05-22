/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:51:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/22 08:54:09 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_search(t_list *bluepill, int x)
{
	int n;
	int m;
	int i;
	
	n = 0;
	m = 0;
	while (bluepill != NULL)
	{
		if (bluepill->content >= x)
			n++;
		if (bluepill->content < x)
			m++;
		bluepill = bluepill->next;	
	}
	n--;
	if (n >= m)
		i = n - m;
	if (m >= n)
		i = m - n;
	return (i);
}

int	is_median(t_list *bluepill)
{
	int i;
	int median;

	i = 1;
	median = 2000;
	while (i <= ft_lstsize(bluepill))
	{
		if (median_search(bluepill, ft_lstcontent(bluepill, i)) < median)
			median = median_search(bluepill, ft_lstcontent(bluepill, i));
		i++;
	}
	return (median);
}

void	spliting(t_list **bluepill, t_list **redpill)
{
	// int median;
	int i;
	// int n;
	
	(void)redpill;
	// median = is_median(*bluepill);
	ft_printf("\n\nBEGINNING\n");
	printing(*bluepill, *redpill);
	ft_printf("\n\n\n");
	i = 0;
	// n = ft_lstsize(*bluepill);
	while (i < 4)
	{
		// if ((*bluepill)->content < median)
			pb(bluepill, redpill);
		// else
		// 	ra(bluepill);
	ft_printf("\n\nCEST LA\n");
	printing(*bluepill, *redpill);
	ft_printf("\n\n\n");
	i++;
	}
	ft_printf("\n\nBASTA COSI\n");
	printing(*bluepill, *redpill);
	ft_printf("\n\n\n");
}

int	main(int argc, char **argv)
{
	t_list	*bluepill;
	t_list	*redpill;

	if (argc == 1)
		return (0);
	if (argc < 3 || parsing(argv, &bluepill) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	parsing(argv, &bluepill);
	redpill = NULL;
	printing(bluepill, redpill);
	ft_printf("\n\n");

	spliting(&bluepill, &redpill);

	printing(bluepill, redpill);
	ft_printf("\n\n");
	return (0);
}
