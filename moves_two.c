/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:49:33 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 07:21:16 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_list **redpill)
{
	t_list	*tmp;

	if (*redpill == NULL)
		return (1);
	tmp = *redpill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew((*redpill)->content);
	if (tmp->next == NULL)
		return (0);
	tmp = *redpill;
	*redpill = (*redpill)->next;
	free(tmp);
	ft_printf("rb\n");
	return (1);
}

int	ra(t_list **bluepill)
{
	t_list	*tmp;

	if (*bluepill == NULL)
		return (1);
	tmp = *bluepill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew((*bluepill)->content);
	if (tmp->next == NULL)
		return (0);
	tmp = *bluepill;
	*bluepill = (*bluepill)->next;
	free(tmp);
	ft_printf("ra\n");
	return (1);
}

void	rrr(t_list **bluepill, t_list **redpill, t_struct *data)
{
	data->is_rrr = 1;
	rra(bluepill, data);
	rrb(redpill, data);
	ft_printf("rrr\n");
	data->is_rrr = 0;
}

int	rrb(t_list **redpill, t_struct *data)
{
	t_list	*tmp;
	t_list	*new;

	if (*redpill == NULL || (*redpill)->next == NULL)
		return (1);
	tmp = *redpill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = ft_lstnew(tmp->content);
	if (new == NULL)
		return (0);
	new->next = (*redpill);
	*redpill = new;
	tmp = *redpill;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	new = tmp->next;
	tmp->next = NULL;
	free(new);
	if (data->is_rrr == 1)
		return (1);
	ft_printf("rrb\n");
	return (1);
}

int	rra(t_list **bluepill, t_struct *data)
{
	t_list	*tmp;
	t_list	*new;

	if (*bluepill == NULL || (*bluepill)->next == NULL)
		return (1);
	tmp = *bluepill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = ft_lstnew(tmp->content);
	if (new == NULL)
		return (0);
	new->next = (*bluepill);
	*bluepill = new;
	tmp = *bluepill;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	new = tmp->next;
	tmp->next = NULL;
	free(new);
	if (data->is_rrr == 1)
		return (1);
	ft_printf("rra\n");
	return (1);
}
