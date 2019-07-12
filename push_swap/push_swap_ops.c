/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_ops.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 17:23:15 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 17:23:15 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack(int *dst, const int *src, int len)
{
	int	i;

	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst[i] = src[i];
		}
	}
}

void	swap(t_swap *s, char c)
{
	int		tmp;

	if (c == 'a' || c == 'c')
	{
		if (s->a->len < 2)
			error_push_swap("Error1\n");
		tmp = s->a->stack[0];
		s->a->stack[0] = s->a->stack[1];
		s->a->stack[1] = tmp;
	}
	if (c == 'b' || c == 'c')
	{
		if (s->b->len < 2)
			error_push_swap("Error2\n");
		tmp = s->b->stack[0];
		s->b->stack[0] = s->b->stack[1];
		s->b->stack[1] = tmp;
	}
}

void	push(t_swap *s, char c, int tmp)
{
	if (c == 'a')
	{
		if (s->b->len <= 0)
			error_push_swap("Error3\n");
		tmp = s->b->stack[0];
		s->b->len--;
		move_stack(s->b->stack, s->b->stack + 1, s->b->len);
		if (s->a->len > 0)
			move_stack(s->a->stack + 1, s->a->stack, s->a->len);
		s->a->stack[0] = tmp;
		s->a->len++;
	}
	else if (c == 'b')
	{
		if (s->a->len <= 0)
			error_push_swap("Error4\n");
		tmp = s->a->stack[0];
		s->a->len--;
		move_stack(s->a->stack, s->a->stack + 1, s->a->len);
		if (s->b->len > 0)
			move_stack(s->b->stack + 1, s->b->stack, s->b->len);
		s->b->stack[0] = tmp;
		s->b->len++;
	}
}

void	rotate(t_swap *s, char c)
{
	int		tmp;

	if (c == 'a' || c == 'c')
	{
		if (s->a->len <= 0)
			error_push_swap("Error5\n");
		tmp = s->a->stack[0];
		move_stack(s->a->stack, s->a->stack + 1, s->a->len - 1);
		s->a->stack[s->a->len - 1] = tmp;
	}
	if (c == 'b' || c == 'c')
	{
		if (s->b->len <= 0)
			error_push_swap("Error6\n");
		tmp = s->b->stack[0];
		move_stack(s->b->stack, s->b->stack + 1, s->b->len - 1);
		s->b->stack[s->b->len - 1] = tmp;
	}
}

void	rev_rotate(t_swap *s, char c)
{
	int		tmp;

	if (c == 'a' || c == 'c')
	{
		if (s->a->len <= 0)
			error_push_swap("Error7\n");
		tmp = s->a->stack[s->a->len - 1];
		move_stack(s->a->stack + 1, s->a->stack, s->a->len - 1);
		s->a->stack[0] = tmp;
	}
	if (c == 'b' || c == 'c')
	{
		if (s->b->len <= 0)
			error_push_swap("Error8\n");
		tmp = s->b->stack[s->b->len - 1];
		move_stack(s->b->stack + 1, s->b->stack, s->b->len - 1);
		s->b->stack[0] = tmp;
	}
}
