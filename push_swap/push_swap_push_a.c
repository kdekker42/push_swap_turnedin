/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_push_a.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 20:03:25 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/05 20:03:25 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fix_a(t_swap *s)
{
	int		i;

	i = s->a->len - 1;
	while (A[i] < s->sorted[s->len - 1])
		select_print(s, "rra");
}

static void	check_b(t_swap *s)
{
	if (s->b->len > 1 && B[0] < B[1])
		ss_checker(s, 'b');
}

static int	goodie_push(t_swap *s)
{
	if (A[0] <= s->a->mid || A[1] <= s->a->mid || A[s->a->len - 1] <= s->a->mid)
	{
		check_b(s);
		if (A[0] < A[1] && A[0] < A[s->a->len - 1])
			select_print(s, "pb");
		else if (A[1] < A[0] && A[1] < s->a->stack[s->a->len - 1])
		{
			ss_checker(s, 'a');
			select_print(s, "pb");
		}
		else
		{
			select_print(s, "rra");
			select_print(s, "pb");
		}
		return (1);
	}
	else
	{
		select_print(s, "ra");
		s->fix_a++;
	}
	return (0);
}

int			pushing_a2b(t_swap *s)
{
	return (goodie_push(s));
}
