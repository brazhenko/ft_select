/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:57:32 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/21 17:02:31 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			dcl_push_back(t_dcl **first, t_dcl *next)
{
	dcl_end(first);
	(*first)->next = next;
	next->previous = *first;
}
