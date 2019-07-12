/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_opz.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 17:48:53 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/13 17:48:53 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a_b(t_checker *a, t_checker *b)
{
	rotate(a);
	rotate(b);
}

void	rotate(t_checker *s)
{
	int		tmp;

	tmp = s->stack[s->len - 1];
	move_stack(s->stack + 1, s->stack, s->len);
	s->stack[0] = tmp;
}

void	reverse_rotate_a_b(t_checker *a, t_checker *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	reverse_rotate(t_checker *s)
{
	s->stack[s->len] = s->stack[0];
	move_stack(s->stack, s->stack + 1, s->len);
}
