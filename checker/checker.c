/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 17:56:48 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/03 17:56:49 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		read_move(t_checker *a, t_checker *b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(b);
	else if (ft_strcmp(line, "ss") == 0)
		swap_a_b(a, b);
	else if (ft_strcmp(line, "pa") == 0)
		push(a, b);
	else if (ft_strcmp(line, "pb") == 0)
		push(b, a);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_a_b(a, b);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_rotate_a_b(a, b);
	else
		return (-2);
	return (0);
}

int		read_and_check(t_checker *a, t_checker *b)
{
	char	*line;
	int		i;

	line = 0;
	i = 0;
	while (get_next_line(0, &line))
	{
		if (read_move(a, b, line))
			return (-2);
		ft_strdel(&line);
	}
	return (0);
}

int		control_stack(t_checker *a, t_checker *b, int len)
{
	int		i;

	i = len - 1;
	if (a->len != len || b->len != 0)
		return (-1);
	while (0 < i)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (-1);
		i--;
	}
	return (0);
}

int		build(int argc, char **argv)
{
	t_checker	stack_a;
	t_checker	stack_b;
	int			rtn;

	rtn = 0;
	init_stacks_checker(&stack_a, &stack_b, argc - 1);
	if (get_args(&stack_a, argv) == -2 ||
		read_and_check(&stack_a, &stack_b) == -2)
		return (-2);
	rtn = control_stack(&stack_a, &stack_b, argc - 1);
	free(stack_a.stack);
	free(stack_b.stack);
	return (rtn);
}

int		main(int argc, char **argv)
{
	int		stats;

	stats = 0;
	if (argc > 1)
	{
		stats = build(argc, argv);
		if (stats == 0)
			write(1, "OK\n", 3);
		else if (stats == -2)
			write(1, "Error\n", 6);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
