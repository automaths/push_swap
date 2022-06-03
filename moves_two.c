/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:49:33 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 03:11:09 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **redpill)
{
	t_list	*tmp;

	if (*redpill == NULL)
		return ;
	tmp = *redpill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew((*redpill)->content);
	tmp = *redpill;
	*redpill = (*redpill)->next;
	free(tmp);
	ft_printf("rb\n");
}

void	ra(t_list **bluepill)
{
	t_list	*tmp;

	if (*bluepill == NULL)
		return ;
	tmp = *bluepill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew((*bluepill)->content);
	tmp = *bluepill;
	*bluepill = (*bluepill)->next;
	free(tmp);
	ft_printf("ra\n");
}

void	rrr(t_list **bluepill, t_list **redpill, t_struct *data)
{
	data->is_rrr = 1;
	rra(bluepill, data);
	rrb(redpill, data);
	ft_printf("rrr\n");
	data->is_rrr = 0;
}

void	rrb(t_list **redpill, t_struct *data)
{
	t_list	*tmp;
	t_list	*new;

	if (*redpill == NULL || (*redpill)->next == NULL)
		return ;
	tmp = *redpill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = ft_lstnew(tmp->content);
	new->next = (*redpill);
	*redpill = new;
	tmp = *redpill;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	new = tmp->next;
	tmp->next = NULL;
	free(new);
	if (data->is_rrr == 1)
		return ;
	ft_printf("rrb\n");
}

void	rra(t_list **bluepill, t_struct *data)
{
	t_list	*tmp;
	t_list	*new;

	if (*bluepill == NULL || (*bluepill)->next == NULL)
		return ;
	tmp = *bluepill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = ft_lstnew(tmp->content);
	new->next = (*bluepill);
	*bluepill = new;
	tmp = *bluepill;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	new = tmp->next;
	tmp->next = NULL;
	free(new);
	if (data->is_rrr == 1)
		return ;
	ft_printf("rra\n");
}
