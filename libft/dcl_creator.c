/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:56:39 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/21 17:02:01 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dcl			*dcl_creator(char c, int n)
{
	t_dcl *new;

	new = (t_dcl *)malloc(sizeof(t_dcl));
	new->c = c;
	new->n = n;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
