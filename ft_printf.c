/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:58:23 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/16 16:18:39 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const	char *str, ...)
{
	size_t	i;
	va_list	aptr;
	size_t	tmp;

	i = 0;
	va_start(aptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			tmp = i;
			while (str[i] == ' ' && str[i + 1])
				i++;
			if (str[i] != '%' && tmp != i)
				return (0);
		}
		i++;
	}
	return (ft_printfnbr(str, aptr));
}
