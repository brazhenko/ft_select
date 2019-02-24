/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:48:01 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/21 17:37:33 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ft_dst;
	char		*ft_src;

	if (!dst && !src)
		return (NULL);
	ft_dst = (char *)dst;
	ft_src = (char *)src;
	while (n)
	{
		*(ft_dst++) = *(ft_src++);
		n--;
	}
	return (dst);
}
