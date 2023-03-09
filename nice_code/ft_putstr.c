/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:55:45 by wbousfir          #+#    #+#             */
/*   Updated: 2023/03/09 22:56:54 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	size_t	x;

	if (!s)
		return ;
	x = 0;
	while (s[x])
	{
		write(1, &s[x], 1);
		x++;
	}
}