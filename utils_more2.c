/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:02:05 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 08:45:06 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sign_one(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
		{
			j = 0;
			i++;
		}
		while (str[i] && str[i] != ' ')
		{
			if (str[i] == '-' || str[i] == '+')
				j++;
			if ((j > 1) || (j == 1 && (str[0] != '-' && str[0] != '+')))
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_sign_two(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_sign_one(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_list *bluepill)
{
	if (!bluepill)
		return (1);
	while (bluepill->next != NULL)
	{
		if (bluepill->content > bluepill->next->content)
			return (0);
		bluepill = bluepill->next;
	}
	return (1);
}
