/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 19:08:17 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/26 19:08:18 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_empty(t_swap *s, int b)
{
	if (b == 0)
		select_print(s, "ra");
	else if (b == 1)
		select_print(s, "rra");
	if (s->a->stack[0] > s->a->stack[1])
		ss_checker(s, 'a');
	s->sort = s->a->len;
}

void	a_full(t_swap *s, int b)
{
	if (b == 0)
	{
		ss_checker(s, 'a');
		select_print(s, "ra");
		ss_checker(s, 'a');
		select_print(s, "rra");
	}
	else if (b == 1)
	{
		select_print(s, "ra");
		ss_checker(s, 'a');
		select_print(s, "rra");
	}
	if (s->a->stack[0] > s->a->stack[1])
		ss_checker(s, 'a');
	s->sort = s->a->len;
}

void	edge_case(t_swap *s)
{
	while (s->b->len > 0)
		select_print(s, "pa");
	sort_a(s);
}

int		sum_mid(t_swap *s)
{
	int		j;
	int		sum;

	j = 0;
	sum = 0;
	while (j <= s->i)
	{
		sum += s->midians[j];
		j++;
	}
	return (sum);
}
