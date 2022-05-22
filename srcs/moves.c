/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 02:16:12 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/22 04:40:39 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list *bluepill, t_list *redpill)
{
	sa(bluepill);
	sb(redpill);
}

void	sb(t_list *redpill)
{
	int	tmp;

	if (ft_lstsize(redpill) < 2)
		return ;
	tmp = redpill->content;
	redpill->content = redpill->next->content;
	redpill->next->content = tmp;
}

void	sa(t_list *bluepill)
{
	int	tmp;

	if (ft_lstsize(bluepill) < 2)
		return ;
	tmp = bluepill->content;
	bluepill->content = bluepill->next->content;
	bluepill->next->content = tmp;
}

void	pa(t_list **bluepill, t_list **redpill)
{
	t_list *tmp;	
	if ((*redpill) == NULL)
		return ;
	if ((*bluepill) == NULL)
	{
		(*bluepill) = ft_lstnew((*redpill)->content);
		tmp = (*redpill);
		(*redpill) = (*redpill)->next;
		free(tmp);
		return ;
	}
	tmp = ft_lstnew((*redpill)->content);
	tmp->next = *bluepill;
	*bluepill = tmp;
	tmp = (*redpill);
	(*redpill) = (*redpill)->next;
	free(tmp);
}

void	pb(t_list **bluepill, t_list **redpill)
{
	t_list *tmp;	
	if ((*bluepill) == NULL)
		return ;
	if ((*redpill) == NULL)
	{
		(*redpill) = ft_lstnew((*bluepill)->content);
		tmp = (*bluepill);
		(*bluepill) = (*bluepill)->next;
		free(tmp);
		return ;
	}
	tmp = ft_lstnew((*bluepill)->content);
	tmp->next = *redpill;
	*redpill = tmp;
	tmp = (*bluepill);
	(*bluepill) = (*bluepill)->next;
	free(tmp);
}

void	rr(t_list **bluepill, t_list **redpill)
{
	ra(bluepill);
	rb(redpill);
}

void	rb(t_list **redpill)
{
	t_list *tmp;
	
	if (*redpill == NULL)
		return ;
	tmp = *redpill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew((*redpill)->content);
	tmp = *redpill;
	*redpill = (*redpill)->next;
	free(tmp);
}

void	ra(t_list **bluepill)
{
	t_list *tmp;
	
	if (*bluepill == NULL)
		return ;
	tmp = *bluepill;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew((*bluepill)->content);
	tmp = *bluepill;
	*bluepill = (*bluepill)->next;
	free(tmp);
}

void	rrr(t_list **bluepill, t_list **redpill)
{
	rra(bluepill);
	rrb(redpill);
}

void	rrb(t_list **redpill)
{
	t_list *tmp;
	t_list *new;
	
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
}

void	rra(t_list **bluepill)
{
	t_list *tmp;
	t_list *new;
	
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
}
