/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_ops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:00:07 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/03 18:00:08 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_checker *stack)
{
	int	tmp;

	tmp = 0;
	if (stack->len < 2)
		return ;
	tmp = stack->stack[stack->len - 1];
	stack->stack[stack->len - 1] = stack->stack[stack->len - 2];
	stack->stack[stack->len - 2] = tmp;
}

void	swap_a_b(t_checker *a, t_checker *b)
{
	if (a->len < 2 || b->len < 2)
		return ;
	swap(a);
	swap(b);
}

void	push(t_checker *a, t_checker *b)
{
	int	tmp;

	if (b->len <= 0)
		return ;
	tmp = 0;
	tmp = b->stack[b->len - 1];
	b->len--;
	a->len++;
	a->stack[a->len - 1] = tmp;
}

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
