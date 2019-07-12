/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 16:36:14 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 16:36:14 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_swap *s)
{
	int		b;

	if (sorted(s))
	{
		s->sort = s->a->len;
		return ;
	}
	b = 0;
	b = (s->a->stack[0] > s->a->stack[1]) ? b : 1;
	b = (s->a->stack[b] > s->a->stack[2]) ? b : 2;
	if (s->sort == 0)
		a_empty(s, b);
	else
		a_full(s, b);
	s->a_goodie = 0;
}

void	divide_b(t_swap *s)
{
	int		p[2];
	int		j;
	int		tmp;

	p[1] = 0;
	p[0] = s->midians[s->i];
	tmp = p[0];
	j = s->i;
	if (s->b->len <= 3)
	{
		edge_case(s);
		return ;
	}
	get_mid_b(s);
	while (p[0] > s->midians[j])
	{
		if (pushing_b2a(s, tmp))
			p[0]--;
		p[1]++;
	}
	if (s->fix_b == 1)
		fix_b(s);
}

int		sorted(t_swap *s)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = sum_mid(s);
	while (s->a->stack[i] < s->a->stack[i + 1] && i < s->a->len - s->sort - 1)
		i++;
	if (i == s->a->len - s->sort - 1)
	{
		while (tmp > s->b->len)
		{
			if (s->midians[s->i] == 0)
				s->i--;
			s->midians[s->i]--;
			tmp--;
		}
		s->a_goodie = 1;
		return (1);
	}
	return (0);
}

void	divide_a(t_swap *s)
{
	int		p;

	p = 0;
	get_mid_a(s);
	while (p < s->midians[s->i])
	{
		if (sorted(s))
			break ;
		if (pushing_a2b(s))
			p++;
	}
	if (s->sort > 0)
		fix_a(s);
}

void	sort(t_swap *s)
{
	while ((int)s->len - (int)s->sort > 0)
	{
		if (((int)s->a->len - (int)s->sort <= 3 && \
			(int)s->a->len - (int)s->sort > 0) \
			|| s->a_goodie == 1)
			sort_a(s);
		else if ((int)s->sort == (int)s->a->len)
			divide_b(s);
		else
			divide_a(s);
	}
}
