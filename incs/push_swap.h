#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct s_struct
{
	int *bluepill;
	int sizeblue;
	int *redpill;
	int sizered;
	int sizemax;
} matrix;

void	matrix_init(matrix *pills, int argc, char **argv);
void	read_pills(matrix *pills);
void	move_sa(matrix *pills);
void	move_sb(matrix *pills);
void	move_ss(matrix *pills);
void	move_pa(matrix *pills);
void	move_pb(matrix *pills);
void	move_ra(matrix *pills);
void	move_rb(matrix *pills);
void	move_rr(matrix *pills);
void	move_rra(matrix *pills);
void	move_rrb(matrix *pills);
void	move_rrr(matrix *pills);


#endif