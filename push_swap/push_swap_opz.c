/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_opz.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 18:10:43 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 18:10:44 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_checker(t_swap *s, char c)
{
	if (s->a->stack[0] > s->a->stack[1] && s->b->stack[0] < s->b->stack[1] &&
		s->a->len > 1 && s->b->len > 1)
	{
		swap(s, 'c');
		ft_printf("%s\n", "ss");
		return ;
	}
	swap(s, c);
	if (c == 'a' && s->a->len > 1)
		ft_printf("%s\n", "sa");
	else if (s->b->len > 1)
		ft_printf("%s\n", "sb");
}

void	rr_checker(t_swap *s, char c)
{
	if (s->a->stack[0] > s->a->stack[s->a->len - 1] && \
		s->b->stack[0] < s->b->stack[s->a->len - 1] && \
		s->a->len > 1 && s->b->len > 1)
	{
		rotate(s, 'c');
		ft_printf("%s\n", "rr");
		return ;
	}
	rotate(s, c);
	if (c == 'a' && s->a->len > 1)
		ft_printf("%s\n", "ra");
	else if (s->b->len > 1)
		ft_printf("%s\n", "rb");
}

void	rrr_checker(t_swap *s, char c)
{
	if (s->a->stack[0] > s->a->stack[s->a->len - 1] && \
		s->b->stack[0] > s->b->stack[s->a->len - 1] && \
		s->a->len > 1 && s->b->len > 1)
	{
		rev_rotate(s, 'c');
		ft_printf("%s\n", "rrr");
		return ;
	}
	rev_rotate(s, c);
	if (c == 'a' && s->a->len > 1)
		ft_printf("%s\n", "rra");
	else if (s->b->len > 1)
		ft_printf("%s\n", "rrb");
}

void	select_print(t_swap *s, char *str)
{
	if (!ft_strcmp(str, "sa"))
		swap(s, 'a');
	else if (!ft_strcmp(str, "sb"))
		swap(s, 'b');
	else if (!ft_strcmp(str, "ss"))
		swap(s, 'c');
	else if (!ft_strcmp(str, "pa"))
		push(s, 'a', 0);
	else if (!ft_strcmp(str, "pb"))
		push(s, 'b', 0);
	else if (!ft_strcmp(str, "ra"))
		rotate(s, 'a');
	else if (!ft_strcmp(str, "rb"))
		rotate(s, 'b');
	else if (!ft_strcmp(str, "rr"))
		rotate(s, 'c');
	else if (!ft_strcmp(str, "rra"))
		rev_rotate(s, 'a');
	else if (!ft_strcmp(str, "rrb"))
		rev_rotate(s, 'b');
	else if (!ft_strcmp(str, "rrr"))
		rev_rotate(s, 'c');
	else
		error_push_swap("error\n");
	ft_printf("%s\n", str);
}
