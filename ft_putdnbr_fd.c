/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:28:10 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/15 15:27:10 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	verif_base(char *base)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (x < ft_strlen(base))
	{
		while (i < ft_strlen(base))
		{
			if (base[x] == base[i] && i != x)
				return (0);
			if (base[x] == '+' || base[x] == '-')
				return (0);
			i++;
		}
		i = 0;
		x++;
	}
	return (1);
}

void	ft_putdnbr_fd(size_t nbr, int fd, char *base)
{
	size_t		i;
	char		arr[16];
	int			temp;
	size_t		nb;

	i = 0;
	temp = 0;
	nb = nbr;
	if (nb == 0)
		ft_putchar_fd(base[0], fd);
	if (nb < 0 && verif_base(base) == 1)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	while (nb > 0 && verif_base(base) == 1)
	{
		temp = nb % ft_strlen(base);
		arr[i] = base[temp];
		nb /= ft_strlen(base);
		i++;
	}
	while (i-- > 0 && verif_base(base) == 1)
		ft_putchar_fd(arr[i], fd);
}
