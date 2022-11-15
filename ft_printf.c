/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:41:53 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/15 21:53:35 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printfarg(char c, va_list aptr)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(aptr, int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(aptr, char *), 1);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putdnbr_fd(va_arg(aptr, size_t), 1, "0123456789abcdef");
	}
	else if (c == 'd')
		ft_putddnbr_fd(va_arg(aptr, int), 1, "0123456789");
	else if (c == 'i')
		ft_putnbr_fd(va_arg(aptr, int), 1);
	else if (c == 'u')
		ft_putunbr_fd(va_arg(aptr, unsigned int), 1);
	else if (c == 'x')
		ft_putdnbr_fd(va_arg(aptr, unsigned long), 1, "0123456789abcdef");
	else if (c == 'X')
		ft_putdnbr_fd(va_arg(aptr, unsigned long), 1, "0123456789ABCDEF");
	else
		ft_putchar_fd(va_arg(aptr, int), 1);
}

static void	afficherstr(const char *str, va_list aptr)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			while (str[i] == ' ' && str[i + 1])
				i++;
			ft_printfarg(str[i], aptr);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
}

int	scounter(char c, va_list aptr)
{
	int	x;

	x = 0;
	if (c == 'c')
		x = 1;
	else if (c == '%')
		x = 1;
	else if (c == 's')
		x = ft_strlen(va_arg(aptr, char *)) - 1;
	else if (c == 'p')
		x = 8;
	else if (c == 'd')
		x = ft_pow(va_arg(aptr, int));
	else if (c == 'i')
		x = ft_pow(va_arg(aptr, int));
	else if (c == 'u')
		x = ft_pow(va_arg(aptr, int));
	else if (c == 'x')
		x = ft_power_base(va_arg(aptr, int));
	else if (c == 'X')
		x = ft_power_base(va_arg(aptr, int));
	else
		x = 1;
	return (x);
}

static int	nbchar(const char *s, va_list aptr)
{
	size_t	i;
	size_t	x;
	size_t	tmp;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			tmp = i;
			while (s[i] == ' ' && s[i + 1])
				i++;
			if (s[i] != '%' && tmp != i)
				return (0);
			x += scounter(s[i], aptr);
			i++;
		}
		else
		{
			i++;
			x++;
		}
	}
	return (x);
}

int	ft_printf(const	char *str, ...)
{
	size_t	i;
	va_list	aptr;
	va_list	aptr2;
	size_t	tmp;
	int		rep;
	
	i = 0;
	va_start(aptr, str);
	va_start(aptr2, str);
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
	i = 0;
	afficherstr(str, aptr);
	rep = nbchar(str, aptr2);
	return (rep);
}
