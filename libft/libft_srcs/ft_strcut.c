/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:54:45 by clonger           #+#    #+#             */
/*   Updated: 2019/06/18 08:55:24 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strcut(char *str, int start, int c)
{
	if (c)
		start = ft_charnchr(str, start, c);
	ft_strclr(&str[start]);
}
