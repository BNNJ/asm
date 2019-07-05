/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:00:22 by clonger           #+#    #+#             */
/*   Updated: 2018/01/08 14:25:50 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_lcompatible(char cflag, char *clength)
{
	int		ret;

	ret = 0;
	if (!clength)
		return (0);
	if (cflag == 'S' || cflag == 'C' || cflag == 'p')
		return (0);
	else if (cflag == 's' || cflag == 'c')
	{
		if (ft_strequ(clength, "l"))
			ret = 1;
	}
	else
		ret = 1;
	return (ret);
}

char		*ft_find_length(char *flag, char cflag, int start)
{
	if (ft_strchr(&flag[start], 'z') && ft_is_lcompatible(cflag, "z"))
		return ("z");
	if (ft_strchr(&flag[start], 'j') && ft_is_lcompatible(cflag, "j"))
		return ("j");
	if (ft_strstr(&flag[start], "ll") && ft_is_lcompatible(cflag, "ll"))
		return ("ll");
	if (ft_strchr(&flag[start], 'l') && ft_is_lcompatible(cflag, "l"))
		return ("l");
	if (ft_strstr(&flag[start], "hh") && ft_is_lcompatible(cflag, "hh"))
		return ("hh");
	if (ft_strchr(&flag[start], 'h') && ft_is_lcompatible(cflag, "h"))
		return ("h");
	return (NULL);
}

char		*ft_is_length(char *flag, int start)
{
	char	*clength;
	char	cflag;

	cflag = ft_is_flag(flag, 0, 1);
	if (!(clength = ft_find_length(flag, cflag, start)))
		return (NULL);
	if (ft_is_lcompatible(cflag, clength))
		return (clength);
	else
		return (NULL);
}
