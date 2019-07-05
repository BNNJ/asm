/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:39 by clonger           #+#    #+#             */
/*   Updated: 2017/11/09 18:05:39 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*str;

	str = (t_list *)ft_memalloc(sizeof(t_list));
	if (!str)
		return (NULL);
	if (!content)
	{
		str->content = NULL;
		str->content_size = 0;
	}
	else
	{
		str->content = (void *)ft_memalloc(content_size);
		ft_memcpy(str->content, content, content_size);
		str->content_size = content_size;
	}
	str->next = NULL;
	return (str);
}
