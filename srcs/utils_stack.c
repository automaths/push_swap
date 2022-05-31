/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 02:16:04 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/31 03:42:50 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list **bluepill)
{
	t_list	*tmp_one;
	t_list	*tmp_two;

	tmp_one = *bluepill;
	while (tmp_one->next != NULL)
	{
		tmp_two = tmp_one;
		tmp_two = tmp_two->next;
		while (tmp_two != NULL)
		{
			if (tmp_one->content == tmp_two->content)
				return (0);
			tmp_two = tmp_two->next;
		}
		tmp_one = tmp_one->next;
	}
	return (1);
}

int	parsing_one(char *str, t_list **bluepill)
{
	char		**split;
	int			i;
	t_list		*tmp;

	split = ft_split(str, ' ');
	*bluepill = ft_lstnew(ft_atoi(split[0]));
	tmp = *bluepill;
	i = 1;
	while (split[i])
	{
		if (ft_atoi(split[i]) == 0 && (split[i][0] != '0'
			|| ft_strlen(split[i]) != 1))
			return (0);
		(*bluepill)->next = ft_lstnew(ft_atoi(split[i]));
		if ((*bluepill)->next == NULL)
			return (0);
		(*bluepill) = (*bluepill)->next;
		i++;
	}
	*bluepill = tmp;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (check_duplicates(bluepill) == 0)
		return (0);
	return (1);
}

int	parsing_two(char **argv, t_list **bluepill)
{
	int			i;
	t_list		*tmp;

	*bluepill = ft_lstnew(ft_atoi(argv[1]));
	tmp = *bluepill;
	i = 2;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0 && (argv[i][0] != '0'
			|| ft_strlen(argv[i]) != 1))
			return (0);
		(*bluepill)->next = ft_lstnew(ft_atoi(argv[i]));
		if ((*bluepill)->next == NULL)
			return (0);
		(*bluepill) = (*bluepill)->next;
		i++;
	}
	*bluepill = tmp;
	if (check_duplicates(bluepill) == 0)
		return (0);
	return (1);
}
