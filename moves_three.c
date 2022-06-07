/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:53:28 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 07:21:36 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr_one(t_list **bluepill)
{
	t_list	*tmp;

	if (*bluepill != NULL)
	{
		tmp = *bluepill;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew((*bluepill)->content);
		if (tmp->next == NULL)
			return (0);
		tmp = *bluepill;
		*bluepill = (*bluepill)->next;
		free(tmp);
	}
	return (1);
}

int	rr_two(t_list **redpill)
{
	t_list	*tmp;

	if (*redpill != NULL)
	{
		tmp = *redpill;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew((*redpill)->content);
		if (tmp->next == NULL)
			return (0);
		tmp = *redpill;
		*redpill = (*redpill)->next;
		free(tmp);
	}
	return (1);
}

int	rr(t_list **bluepill, t_list **redpill)
{
	if (rr_one(bluepill) == 0)
		return (0);
	if (rr_two(redpill) == 0)
		return (0);
	ft_printf("rr\n");
	return (1);
}
