/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_push.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 16:51:46 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 16:51:47 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fix_b(t_swap *s)
{
	int		i;

	i = s->b->len - 1;
	while (s->b->stack[i] >= s->sorted[s->midians[0]])
	{
		select_print(s, "rrb");
	}
	s->fix_b = 0;
}

static void	check_a(t_swap *s)
{
	if (s->a->stack[0] > s->a->stack[1])
		ss_checker(s, 'a');
}

int			tmp_3(t_swap *s)
{
	int		b;

	b = 0;
	b = (s->b->stack[0] > s->b->stack[1]) ? b : 1;
	b = (s->b->stack[0] > s->b->stack[2]) ? b : 2;
	check_a(s);
	if (b == 0)
		select_print(s, "pa");
	else if (b == 1)
	{
		ss_checker(s, 'b');
		select_print(s, "pa");
	}
	if (b == 2)
	{
		select_print(s, "rb");
		ss_checker(s, 'b');
		select_print(s, "pa");
		select_print(s, "rrb");
	}
	return (1);
}

static void	push_to_a(t_swap *s)
{
	while (1)
	{
		if (s->b->stack[0] > s->b->mid || s->b->stack[1] > s->b->mid)
		{
			check_a(s);
			if (s->b->stack[0] > s->b->stack[1])
				select_print(s, "pa");
			else
			{
				ss_checker(s, 'b');
				select_print(s, "pa");
			}
			break ;
		}
		else
		{
			if (s->b->len == 0)
				break ;
			select_print(s, "rb");
			s->fix_b = 1;
		}
	}
}

int			pushing_b2a(t_swap *s, int tmp)
{
	if (tmp <= 3 && s->b->len > 1)
		return (tmp_3(s));
	else
		push_to_a(s);
	return (1);
}
