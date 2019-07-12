/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 21:37:07 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/13 21:37:07 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_stacks_checker(t_checker *stack_a, t_checker *stack_b, int len)
{
	stack_a->stack = (int *)malloc(sizeof(int) * len + 1);
	stack_a->original_len = len;
	stack_a->sorted_amount = 0;
	stack_a->len = len;
	stack_a->mid = 0;
	stack_b->stack = (int *)malloc(sizeof(int) * len + 1);
	stack_b->original_len = len;
	stack_b->sorted_amount = 0;
	stack_b->len = 0;
	stack_b->mid = 0;
}

int		check_nbr(char *str)
{
	int		i;
	int		value;
	int		neg;

	i = 0;
	value = 0;
	neg = 0;
	if (str[i] == '-')
	{
		neg++;
		i++;
	}
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]) || value > 214748364 || \
			(value == 214748364 && str[i] - 48 > 7 + neg))
			return (0);
		value *= 10;
		value += str[i] - 48;
		i++;
	}
	if (i - neg > 10)
		return (0);
	return (1);
}

int		check_duplicates(int *array, int new, int len)
{
	int		i;

	i = 0;
	len = len - 1;
	while (len > 0 && i < len)
	{
		if (array[i] == new)
			return (1);
		i++;
	}
	return (0);
}

int		get_args(t_checker *a, char **argv)
{
	int		i;
	int		j;

	i = a->len;
	j = 0;
	while (i > 0)
	{
		if (check_duplicates(a->stack, ft_atoi(argv[i]), j + 1))
			return (-2);
		((int *)(a->stack))[j] = (int)ft_atoi(argv[i]);
		if ((a->stack[j] == 0 && argv[i][0] != '0') || \
			!check_nbr(argv[i]))
			return (-2);
		i--;
		j++;
	}
	return (0);
}
