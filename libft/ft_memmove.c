/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:57:00 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 16:57:01 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	size_t		n;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	n = len;
	if (str1 > str2)
		while (i < --n)
			str1[n - 1] = str2[n - 1];
	i = -1;
	if (str1 <= str2)
		while (++i < n)
			str1[i] = str2[i];
	return (dst);
}
