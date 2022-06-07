/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 02:16:04 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 08:25:14 by nsartral         ###   ########.fr       */
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	fill_list(char **split, t_list **bluepill)
{
	int	i;

	i = 1;
	if (split[0] == NULL)
		return (0);
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
	return (1);
}

int	parsing_one(char *str, t_list **bluepill)
{
	char		**split;
	t_list		*tmp;

	*bluepill = NULL;
	split = ft_split(str, ' ');
	if (split == NULL)
		return (0);
	*bluepill = ft_lstnew(ft_atoi(split[0]));
	if (*bluepill == NULL || check_argv2(split) == 0)
	{
		free_split(split);
		return (0);
	}
	tmp = *bluepill;
	if (fill_list(split, bluepill) == 0)
	{
		free_split(split);
		return (0);
	}
	*bluepill = tmp;
	free_split(split);
	if (check_duplicates(bluepill) == 0)
		return (0);
	return (1);
}

int	parsing_two(char **argv, t_list **bluepill)
{
	int			i;
	t_list		*tmp;

	*bluepill = ft_lstnew(ft_atoi(argv[1]));
	if (*bluepill == NULL)
		return (0);
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
