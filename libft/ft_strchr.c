/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:32:51 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/05 21:19:09 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char			my_c;
	char			*str;

	my_c = (char)c;
	str = (char *)s;
	while (*str)
	{
		if (*str == my_c)
			return (str);
		str++;
	}
	if (*str == my_c)
		return (str);
	return (NULL);
}
