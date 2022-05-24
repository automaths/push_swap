#include "push_swap.h"

int	median_search(t_list *bluepill, int x)
{
	int n;
	int m;
	int i;
	
	n = 0;
	m = 0;
	while (bluepill != NULL)
	{
		if (bluepill->content >= x)
			n++;
		if (bluepill->content < x)
			m++;
		bluepill = bluepill->next;	
	}
	if (n > 0)
		n--;
	if (n >= m)
		i = n - m;
	else
		i = m - n;
	return (i);
}

int	is_median(t_list *bluepill)
{
	int i;
	int median;
	int max;

	i = 1;
	max = 2000;
	median = 0;
	while (i <= ft_lstsize(bluepill))
	{
		if (median_search(bluepill, ft_lstcontent(bluepill, i)) < max)
		{
			max = median_search(bluepill, ft_lstcontent(bluepill, i));
			median = i;
		}
		i++;
	}
	return (median);
}

void	spliting(t_list **bluepill, t_list **redpill)
{
	int median;
	int size;
	int i;
	
	i = 0;
	if (is_median(*bluepill) == 0)
		return ;
	median = ft_lstcontent(*bluepill, is_median(*bluepill));
	size = ft_lstsize(*bluepill);
	while (i < size)
	{
		if ((*bluepill)->content < median)
			pb(bluepill, redpill);
		else
			ra(bluepill);
		i++;
	}
}

void	cover(t_list **bluepill, t_list **redpill)
{
	while (ft_lstsize(*bluepill) != 0)
		pb(bluepill, redpill);
}
