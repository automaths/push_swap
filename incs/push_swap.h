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

//UTILS_LST
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
int			ft_lstcontent(t_list *lst, int index);
//UTILS_STACK
void		printing(t_list *bluepill, t_list *redpill);
int			parsing(char **argv, t_list **bluepill);
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
void	rra(t_list **bluepill);
void	rrb(t_list **redpill);
void	rrr(t_list **bluepill, t_list **redpill);

#endif