/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:44:49 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 08:30:55 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"

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
int			pa(t_list **bluepill, t_list **redpill);
int			pb(t_list **bluepill, t_list **redpill);
int			rr(t_list **bluepill, t_list **redpill);
int			rb(t_list **redpill);
int			ra(t_list **bluepill);
int			rra(t_list **bluepill, t_struct *data);
int			rrb(t_list **redpill, t_struct *data);
void		rrr(t_list **bluepill, t_list **redpill, t_struct *data);
int			cover(t_list **bluepill, t_list **redpill);
int			sorting(t_list **bluepill, t_list **redpill, t_struct *data);
int			solving(t_list **bluepill, t_list **redpill, t_struct *data);
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
void		sort_min(t_list **bluepill, t_list **redpill, t_struct *data);
void		sort_five(t_list **bluepill, t_list **redpill, t_struct *data);
void		sort_four(t_list **bluepill, t_list **redpill, t_struct *data);
void		sort_special(t_list **bluepill, t_list **redpill, t_struct *data);
void		sort_two(t_list **bluepill);
void		sort_three_one(t_list **bluepill, t_struct *data);
void		sort_three_two(t_list **bluepill, t_struct *data);
void		method_one(t_list *bluepill, t_struct *data);
void		apply_one(t_list **bluepill, t_list **redpill, t_struct *data);
void		freeing(t_list **bluepill, t_list **redpill);
int			check_str(char *str);
int			is_special_char(const char *str);
int			is_sorted(t_list *bluepill);
int			check_argv(int argc, char **argv);
int			check_num(const char *str);
int			check_sign_one(char *str);
int			check_sign_two(char **argv);
int			check_str_arg(char *str);
int			check_argv2(char **argv);
int			check_syntax(const char *str);

#endif