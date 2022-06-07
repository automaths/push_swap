/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:15:39 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 08:44:29 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_special_char(const char *str)
{
	if ((str[0] != '0' && (str[0] != '+' || str[1] != '0')
			&& (str[0] != '-' || str[1] != '0')))
		return (0);
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

int	check_syntax(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
