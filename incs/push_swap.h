/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:44:49 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/30 23:53:05 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_list
{
	int					content;
	struct s_list		*next;
}						t_list;

typedef struct s_struct
{
	int			center;
	int			to_order;
	int			nb_one;
	int			nb_two;
	int			is_halved;
	int			is_rrr;
	int			size_bits;
	int			bluepill_size;
}				t_struct;

void		sa(t_list *bluepill);
void		sb(t_list *redpill);
void		ss(t_list *bluepill, t_list *redpill);
void		pa(t_list **bluepill, t_list **redpill);
void		pb(t_list **bluepill, t_list **redpill);
void		rr(t_list **bluepill, t_list **redpill);
void		rb(t_list **redpill);
void		ra(t_list **bluepill);
void		rra(t_list **bluepill, t_struct *data);
void		rrb(t_list **redpill, t_struct *data);
void		rrr(t_list **bluepill, t_list **redpill, t_struct *data);
void		cover(t_list **bluepill, t_list **redpill);
void		sorting(t_list **bluepill, t_list **redpill, t_struct *data);
void		solving(t_list **bluepill, t_list **redpill, t_struct *data);
char		**ft_split(char const *s, char c);
int			to_power(int nb, int power);
int			find_max_rank(t_list *bluepill);
int			find_bit_max(t_list *bluepill);
int			find_rank(t_list *bluepill, int content);
void		rank_convert(t_list **bluepill);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
int			ft_lstcontent(t_list *lst, int index);
t_list		*ft_lstmap(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			check_duplicates(t_list **bluepill);
int			parsing_two(char **argv, t_list **bluepill);
int			parsing_one(char *str, t_list **bluepill);


void		printing(t_list *bluepill, t_list *redpill);

#endif