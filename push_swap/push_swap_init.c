/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 14:10:29 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 14:10:30 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	if (size == 0)
		return ;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	init_a(t_swap *a, int argc)
{
	a->a = (t_elements *)ft_memalloc(sizeof(t_elements));
	a->b = (t_elements *)ft_memalloc(sizeof(t_elements));
	a->midians = (int *)ft_memalloc(sizeof(int) * 20);
	a->i = -1;
	a->sort = 0;
	a->len = argc - 1;
	a->a->mid = 0;
	a->a->len = argc - 1;
	a->b->mid = 0;
	a->b->len = 0;
	a->a->stack = (int *)ft_memalloc(sizeof(int) * argc);
	a->b->stack = (int *)ft_memalloc(sizeof(int) * argc);
	a->fix_b = 0;
	a->fix_a = 0;
	a->a_goodie = 0;
}

void	copy_arrays(t_swap *a, int *tmp)
{
	a->a->stack = (int *)ft_memcpy(a->a->stack, tmp, sizeof(int) * a->a->len);
	sort_int_tab(tmp, a->a->len);
	a->sorted = tmp;
}

void	get_a(t_swap *a, char **argv, int argc)
{
	int			*tmp;
	int			i;

	i = 0;
	tmp = (int *)ft_memalloc(sizeof(int) * argc);
	init_a(a, argc);
	while (argv[i + 1] != 0)
	{
		tmp[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	copy_arrays(a, tmp);
}
