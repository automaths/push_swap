/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:53:28 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/04 01:49:23 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **bluepill, t_list **redpill)
{
	t_list	*tmp;

	if (*bluepill != NULL)
	{
		tmp = *bluepill;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew((*bluepill)->content);
		tmp = *bluepill;
		*bluepill = (*bluepill)->next;
		free(tmp);
	}
	if (*redpill != NULL)
	{
		tmp = *redpill;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew((*redpill)->content);
		tmp = *redpill;
		*redpill = (*redpill)->next;
		free(tmp);
	}
	ft_printf("rr\n");
}

int	check_str_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			if ((str[i] < '0' || str[i] > '9')
				&& str[i] != '-' && str[i] != '+')
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_argv2(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_num(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
