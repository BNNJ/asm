/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:21:59 by clonger           #+#    #+#             */
/*   Updated: 2017/12/02 14:22:02 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_op_sign(char *c)
{
	if (ft_strlen(c) > 1)
		return (0);
	if (c[0] == '+' || c[0] == '-' || c[0] == '/' || c[0] == '*' || c[0] == '%')
		return (1);
	else
		return (0);
}

int			ft_operand(int argc, char **argv)
{
	int		n1;
	int		n2;
	int		result;

	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	result = 0;
	if (argc != 4)
		return (0);
	if (ft_op_sign(argv[2]))
	{
		if (argv[2][0] == '+')
			result = n1 + n2;
		if (argv[2][0] == '-')
			result = n1 - n2;
		if (argv[2][0] == '/')
			result = n1 / n2;
		if (argv[2][0] == '%')
			result = n1 % n2;
		if (argv[2][0] == '*')
			result = n1 * n2;
	}
	else
		return (0);
	return (result);
}
