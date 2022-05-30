/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 02:16:12 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 23:44:28 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list *bluepill, t_list *redpill)
{
	int	tmp;

	if (ft_lstsize(bluepill) >= 2)
	{
	tmp = bluepill->content;
	bluepill->content = bluepill->next->content;
	bluepill->next->content = tmp;
	}
	if (ft_lstsize(redpill) >= 2)
	{
		tmp = redpill->content;
		redpill->content = redpill->next->content;
		redpill->next->content = tmp;
	}
	ft_printf("ss\n");
}

void	sb(t_list *redpill)
{
	int	tmp;

	if (ft_lstsize(redpill) >= 2)
	{
		tmp = redpill->content;
		redpill->content = redpill->next->content;
		redpill->next->content = tmp;
		ft_printf("sb\n");
	}
}

void	sa(t_list *bluepill)
{
	int	tmp;

	if (ft_lstsize(bluepill) >= 2)
	{
		tmp = bluepill->content;
		bluepill->content = bluepill->next->content;
		bluepill->next->content = tmp;
		ft_printf("sa\n");
	}
}

void	pa(t_list **bluepill, t_list **redpill)
{
	t_list	*tmp;

	if ((*redpill) == NULL)
		return ;
	if ((*bluepill) == NULL)
	{
		(*bluepill) = ft_lstnew((*redpill)->content);
		tmp = (*redpill);
		(*redpill) = (*redpill)->next;
		free(tmp);
		ft_printf("pa\n");
		return ;
	}
	tmp = ft_lstnew((*redpill)->content);
	tmp->next = *bluepill;
	*bluepill = tmp;
	tmp = (*redpill);
	(*redpill) = (*redpill)->next;
	free(tmp);
	ft_printf("pa\n");
}

void	pb(t_list **bluepill, t_list **redpill)
{
	t_list	*tmp;

	if ((*bluepill) == NULL)
		return ;
	if ((*redpill) == NULL)
	{
		(*redpill) = ft_lstnew((*bluepill)->content);
		tmp = (*bluepill);
		(*bluepill) = (*bluepill)->next;
		free(tmp);
		ft_printf("pb\n");
		return ;
	}
	tmp = ft_lstnew((*bluepill)->content);
	tmp->next = *redpill;
	*redpill = tmp;
	tmp = (*bluepill);
	(*bluepill) = (*bluepill)->next;
	free(tmp);
	ft_printf("pb\n");
}
