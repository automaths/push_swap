#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

typedef struct s_list
{
	int					content;
	struct s_list		*next;
}						t_list;

typedef struct s_struct
{
	int center;
	int to_order;
	int nb_one;
	int nb_two;
	int is_halved;
	int is_rrr;
	int size_bits;
}				t_struct;

//UTILS_LST
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
int			ft_lstcontent(t_list *lst, int index);
//UTILS_STACK
void		printing(t_list *bluepill, t_list *redpill);
int			parsing_two(char **argv, t_list **bluepill);
int			parsing_one(char *str, t_list **bluepill);
char		**ft_split(char const *s, char c);
//RESOLVE
void	two_numbers(t_list **bluepill);
//MOVES
void	sa(t_list *bluepill);
void	sb(t_list *redpill);
void	ss(t_list *bluepill, t_list *redpill);
void	pa(t_list **bluepill, t_list **redpill);
void	pb(t_list **bluepill, t_list **redpill);
void	rr(t_list **bluepill, t_list **redpill);
void	rb(t_list **redpill);
void	ra(t_list **bluepill);
void	rra(t_list **bluepill, t_struct *data);
void	rrb(t_list **redpill, t_struct *data);
void	rrr(t_list **bluepill, t_list **redpill, t_struct *data);
//SPLITING
int	median_search(t_list *bluepill, int x);
int	is_median(t_list *bluepill);
void	spliting(t_list **bluepill, t_list **redpill);
void	cover(t_list **bluepill, t_list **redpill);

//NB_MOVE
void	method_one(t_list *bluepill, t_struct *data);
void	method_two(t_list *redpill, t_struct *data);
void	apply_one(t_list **bluepill, t_list **redpill, t_struct *data);
void	apply_two(t_list **bluepill, t_list **redpill, t_struct *data);

#endif