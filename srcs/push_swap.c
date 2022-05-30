/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:51:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 02:54:34 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solving(t_list **bluepill, t_list **redpill, t_struct *data)
{
	spliting(bluepill, redpill);
	data->center = ft_lstsize(*bluepill);
	cover(bluepill, redpill);
	while (*redpill != NULL)
	{
		data->to_order = ft_lstcontent(*redpill, 1);
		method_one(*bluepill, data);
		method_two(*redpill, data);
		if (data->nb_one <= data->nb_two)
		{
			apply_one(bluepill, redpill, data);
			ft_printf("\nMETHOD ONE\n");
		}
		else
		{
			apply_two(bluepill, redpill, data);
			ft_printf("\nMETHOD TWO\n");
		}
		printing(*bluepill, *redpill);
		ft_printf("\n\n");
	}
}

int	main(int argc, char **argv)
{
	t_list		*bluepill;
	t_list		*redpill;
	t_struct	data;

	if (argc == 1)
		return (0);
	if (argc == 2 && parsing_one(argv[1], &bluepill) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc >= 3 && parsing_two(argv, &bluepill) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	redpill = NULL;
	solving(&bluepill, &redpill, &data);
	return (0);
}
