/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_mid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 16:50:28 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 16:50:29 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sum_medians(t_swap *s)
{
	int		j;
	int		sum;

	j = 0;
	sum = 0;
	while (j < s->i)
	{
		sum += s->midians[j];
		j++;
	}
	return (sum);
}

void	get_mid_a(t_swap *s)
{
	if (s->len < 6)
	{
		s->midians[s->i] = 2;
		s->a->mid = s->sorted[1];
	}
	else if (s->sort == 0)
	{
		s->i++;
		s->midians[s->i] = ((s->a->len - 1) / 2) + 1;
		s->a->mid = s->sorted[sum_medians(s) + s->midians[s->i] - 1];
	}
	else
	{
		s->i++;
		s->midians[s->i] = (((s->a->len - s->sort) - 1) / 2) + 1;
		s->a->mid = s->sorted[s->b->len + s->midians[s->i] - 1];
	}
}

void	get_mid_b(t_swap *s)
{
	if (s->midians[s->i] > 3)
	{
		s->b->mid = s->sorted[sum_medians(s) + (s->midians[s->i] - 1) / 2];
		s->midians[s->i] = ((s->midians[s->i] - 1) / 2) + 1;
	}
	else
	{
		s->b->mid = s->sorted[sum_medians(s)];
		s->midians[s->i] -= s->midians[s->i];
		s->i--;
	}
}
