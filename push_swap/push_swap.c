/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 13:55:42 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 13:55:43 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_swap		a;
	char		*line;

	line = 0;
	if (argc > 1)
	{
		get_a(&a, argv, argc);
		sort(&a);
	}
	else
		error_push_swap("Not enough arguments!\n");
	return (0);
}
