/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:07:21 by clonger           #+#    #+#             */
/*   Updated: 2017/12/19 18:11:12 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wchrlen(wchar_t wchr)
{
	if (wchr <= 0x7F)
		return (1);
	if (wchr <= 0x7FF)
		return (2);
	if (wchr <= 0xFFFF)
		return (3);
	if (wchr <= 0x10FFFF)
		return (4);
	return (0);
}
