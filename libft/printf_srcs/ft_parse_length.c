/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:54:58 by clonger           #+#    #+#             */
/*   Updated: 2017/12/25 19:11:26 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		ft_changesize(char *flag, intmax_t vint)
{
	char		*clength;

	if (!(clength = ft_is_length(flag, 0)))
		vint = (int)vint;
	if (ft_strequ(clength, "z"))
		vint = (ssize_t)vint;
	if (ft_strequ(clength, "j"))
		vint = (intmax_t)vint;
	if (ft_strequ(clength, "l"))
		vint = (long int)vint;
	if (ft_strequ(clength, "ll"))
		vint = (long long int)vint;
	if (ft_strequ(clength, "h"))
		vint = (short int)vint;
	if (ft_strequ(clength, "hh"))
		vint = (signed char)vint;
	ft_delfchar(flag, 0);
	return (vint);
}

uintmax_t		ft_changeusize(char *flag, uintmax_t vint)
{
	char		*clength;

	if (!(clength = ft_is_length(flag, 0)))
		vint = (unsigned int)vint;
	if (ft_strequ(clength, "z"))
		vint = (size_t)vint;
	if (ft_strequ(clength, "j"))
		vint = (uintmax_t)vint;
	if (ft_strequ(clength, "l"))
		vint = (unsigned long int)vint;
	if (ft_strequ(clength, "ll"))
		vint = (unsigned long long int)vint;
	if (ft_strequ(clength, "h"))
		vint = (unsigned short int)vint;
	if (ft_strequ(clength, "hh"))
		vint = (unsigned char)vint;
	ft_delfchar(flag, 0);
	return (vint);
}
