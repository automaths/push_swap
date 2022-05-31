/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:07:17 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/31 05:08:38 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeing(t_list **bluepill, t_list **redpill)
{
	t_list	*tmp;

	while (*bluepill != NULL)
	{
		tmp = *bluepill;
		*bluepill = (*bluepill)->next;
		free(tmp);
	}
	while (*redpill != NULL)
	{
		tmp = *redpill;
		*redpill = (*redpill)->next;
		free(tmp);
	}
	if (*bluepill)
		free(*bluepill);
	if (*redpill)
		free(*redpill);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
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
