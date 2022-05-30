/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:53:28 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 03:20:31 by nsartral         ###   ########.fr       */
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
